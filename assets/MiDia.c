// Funcion que pide la hora al usuario , recibe como parametro la frase , la cual da contexto del porque se le esta solicatando al usuario la hora
struct Hora PedirLaHora(char *frase){
    int Horas, minutos;
    struct Hora nuevaHora;

    system("cls");
    p("\n\n\t%s", frase);

    // Se pide la hora al usuario
    p("\n\n\t\tHora: ");
    s("%d",&Horas);

    // Se pide los minutos
    p("\n\n\t\tMinutos: ");
    s("%d", &minutos);

    nuevaHora.Horas = Horas;
    nuevaHora.minutos = minutos;

    system("cls");
    
    return nuevaHora;
}

// Funcion que agrega actividades
enum boolean AgregarActividad(struct nodo **listActividad, struct Fecha fechaDeHoy){

    int NumActividad , ide, respuesta;
    char *NombreActividad, *lugar, *descripcion;
    struct Hora thisHora;
    struct activity NuevaActividad;
    NuevaActividad.thisFecha = fechaDeHoy; //Se ingresa la fecha de hoy en la estructura de actividad
    
    

    respuesta = validar(1,2,"Presiona (1) para agregar la actividad actividad o (2) para cancelar y salir: ");

    if (respuesta == 2)
        return false;

    while(respuesta == 1){

        thisHora  = PedirLaHora("Ingres la hora en que va ocurrir el evento o la actividad");//Se pide la hora al usuario
        ide = (thisHora.Horas * 100) + (thisHora.minutos); // Esto sirve para que el ide de la actividad tenga la hora pero "concatenada y casteada a entero", ejemplo: La hora es 03:11 entonces ide = 311
        NuevaActividad.NumActividad = ide;                 // Se ingresa lo que se obtuvo de la transformacion de ide al  numero de actividad
        NuevaActividad.thisHora = thisHora;                // Se ingresa la hora en el evento 

        // Se pide al usuario la info que requiere un evento o actvidad
        system("cls");

        p("\n\n\tIngresa el titulo del evento o actividad: ");
        s("%s", &NombreActividad);
        fflush(stdin);

        p("\n\n\tIngresa el lugar del evento o actividad: ");
        s("%s", &lugar);
        fflush(stdin);

        p("\n\n\tIngresa la descripcion del evento o actividad: ");
        s("%s", &descripcion);
        fflush(stdin);

        respuesta = validar(1, 3, "Presiona (1) para volver a ingresar los datos, (2) para confirmar o (3) para cancelar y salir: ");
        if(respuesta == 3)
            return false;
    }

    NuevaActividad.NombreActividad = NombreActividad;
    NuevaActividad.lugar = lugar;
    NuevaActividad.descripcion = descripcion;

    struct nodo *NuevoNodoDeActividad = (nodo *) malloc(sizeof(nodo)); //Se crea un nuevo nodo
    NuevoNodoDeActividad -> thisActivity = NuevaActividad;
    NuevoNodoDeActividad -> id = ide;

    MostrarActividad(NuevaActividad);

    return add(listActividad , &NuevoNodoDeActividad , &ide);
}

// Funcion que muestra la hora, recibiendo como parametro una estructura de tipo hora
void MostrarHora(struct Hora thisHora){
    p("\n\tHora: %d : %d", thisHora.Horas, thisHora.minutos);
}

// Funcion que muestra la fecha, recibiendo como parametro una estructura de tipo Fecha
void MostrarFecha(struct Fecha thisFecha)
{
    p("\n\tFecha: %d / %d / %d", thisFecha.dia , thisFecha.mes, thisFecha.anio);
}

// Aqui hay problemas
// Funcion que muestra una actividad, recibiendo como parametro una estructura de tipo activity
void MostrarActividad(struct activity Evento){
    system("cls");
    p("\n\n\tNo. Actividad: %d \t Nombre de la actividad: %s\n\n\tLugar: %s", Evento.NumActividad, Evento.NombreActividad, Evento.lugar);
    MostrarFecha(Evento.thisFecha);
    MostrarHora(Evento.thisHora);
    p("\n\n\n\tDescripcion:\n\n%s\n\t", Evento.descripcion);

}

// Funcion que permite recorrer la lista de actividades e imprimir cada una
enum boolean VerActividades(struct nodo **listActividad)
{

    struct nodo *actual = *listActividad;
    int respuesta;

    p("\n\n\tEn la funcion VerActividades");

    if(*listActividad == NULL){
        p("\n\n\tLa lista esta vacia");
        return false;
    }
    else{

        system("cls");

        MostrarActividad(actual->thisActivity);
        respuesta = validar(1, 3, "Elige una opcion\n\n\t(1) Actividad anterior\t\t(2) Salir\t\t(3) Actividad siguiente");
        
        while (respuesta == 1 || respuesta == 3)
        {
            switch (respuesta){

            case 1:
                actual = actual->anterior;
                break;
            
            case 3:
                actual = actual->siguiente;
                break;
            }

            MostrarActividad(actual->thisActivity);

            respuesta = validar(1, 3, "Elige una opcion\n\n\t(1) Actividad anterior\t\t(2) Salir\t\t(3) Actividad siguiente");
        }
        return true;
    }
}

// Funcion del menu de la seccion mmi Dia
void menuMiDia(struct year anioNuevo, struct Fecha fechaDeHoy, SYSTEMTIME tempo)
{

    int respuesta, opcion, numActividades = 0;

    struct day thisDay ;
    thisDay = anioNuevo.listaMeses[fechaDeHoy.mes - 1].listaDias[fechaDeHoy.dia - 1];

    respuesta = answer("seccion mostrar mi dia"); // se pregunta si se desea ingresar al menu principal o salir
    while (respuesta == 1){

        numActividades = CountNodes(&(thisDay.listaActividades));
        system("cls"); // se limpia pantalla
        p("\n\n\tFecha de hoy: %d / %d / %d ", anioNuevo.listaMeses[fechaDeHoy.mes - 1].listaDias[fechaDeHoy.dia - 1].dia, anioNuevo.listaMeses[fechaDeHoy.mes - 1].mes, anioNuevo.anio);
        p("\n\n\tNumero de actividades: %d",numActividades);

        if (numActividades == 0){
            opcion = validar(1,2,"\n\n\tselecciona la opcion que deseas realizar\n\n\t\t1)Agregar actividad\n\n\t\t2)Salir\n\n\t\t:");
            switch (opcion)
            {
            case 1:
                
                // Aqui va la funcion agregar actividad
                system("cls");
                p("\n\n\t%s\n\n\t",((AgregarActividad(&(thisDay.listaActividades), fechaDeHoy)) ? "Se agrego la actividad o evento" : "Se cancelo el procesos"));
                break;
            
            case 2:

                //Salir
                system("cls");
                p("\n\n\tSaliendo ...");

                if (respuesta != 2)
                    respuesta = answer("Menu principal");

                break;
            }
        }else{

            opcion = validar(1, 6, "\n\n\tselecciona la opcion que deseas realizar\n\n\t\t1)Ver Actividades\n\n\t\t2)Agregar actividad\n\n\t\t3)Editar una actividad\n\n\t\t4)Eliminar una actividad\n\n\t\t5)Buscar\n\n\t\t6)Salir\n\n\t\t:");
            switch (opcion){
            case 1:

                // Aqui va la funcion ver actividadades
                system("cls");
                p("\n\n\t%s\n\n\t", ((VerActividades(&(thisDay.listaActividades))) ? "Mostrando actividades" : "No hay actividades que mostrar"));

                break;
            case 2:

                // Aqui va la funcion agregar actividad
                system("cls");
                p("\n\n\t%s\n\n\t", ((AgregarActividad(&(thisDay.listaActividades), fechaDeHoy)) ? "Se agrego la actividad o evento" : "Se cancelo el procesos"));

                break;
            case 3:

                // Aqui va la funcion editar actividad

                break;
            case 4:

                // Aqui va la funcion eliminar actividad

                break;
            case 5:

                // Aqui va la funcion buscar actividad

                break;
            case 6:

                //Salir
                if (respuesta != 2)
                    respuesta = answer("Menu principal");

                break;
            }
        }
        
        // opcion = validar(1,);
        
        respuesta = answer("seccion mostrar mi dia"); // se pregunta si se desea ingresar al menu principal o salir
    }
}

