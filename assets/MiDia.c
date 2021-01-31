// Funcion que pide la hora al usuario , recibe como parametro la frase , la cual da contexto del porque se le esta solicatando al usuario la hora
struct Hora PedirLaHora(char *frase){
    struct Hora nuevaHora;

    system("cls");
    p("\n\n\t%s", frase);

    nuevaHora.Horas = validar(0,23,"Ingresa la Hora (de 0 a 23): ");
    nuevaHora.minutos = validar(0, 59, "Ingresa los minutos (de 0 a 59): ");

    system("cls");
    
    return nuevaHora;
}

// Funcion que agrega actividades
enum boolean AgregarActividad(struct nodo **listActividad, struct Fecha fechaDeHoy){

    int NumActividad , ide, respuesta;
    char NombreActividad[30], lugar[30], descripcion[30];
    struct Hora thisHora;
    struct activity NuevaActividad;
    NuevaActividad.thisFecha = fechaDeHoy; //Se ingresa la fecha de hoy en la estructura de actividad
    
    

    respuesta = validar(1,2,"Presiona (1) para agregar la actividad actividad o (2) para cancelar y salir: ");

    if (respuesta == 2)
        return false;

    while(respuesta == 1){

        thisHora  = PedirLaHora("Ingres la hora en que va ocurrir el evento o la actividad");//Se pide la hora al usuario
        ide = (thisHora.Horas * 100) + (thisHora.minutos); // Esto sirve para que el ide de la actividad tenga la hora pero "concatenada y casteada a entero", ejemplo: La hora es 03:11 entonces ide = 311
        
        // Se pide al usuario la info que requiere un evento o actvidad
        system("cls");

        fflush(stdin);
        p("\n\n\tIngresa el titulo del evento o actividad: ");
        gets(NombreActividad);

        fflush(stdin);
        p("\n\n\tIngresa el lugar del evento o actividad: ");
        gets(lugar);

        fflush(stdin);
        p("\n\n\tIngresa la descripcion del evento o actividad: ");
        gets(descripcion);

        respuesta = validar(1, 3, "Presiona (1) para volver a ingresar los datos, (2) para confirmar o (3) para cancelar y salir: ");
        if(respuesta == 3)
            return false;
    }

    NuevaActividad.NombreActividad = NombreActividad;
    NuevaActividad.lugar = lugar;
    NuevaActividad.descripcion = descripcion;
    NuevaActividad.thisHora = thisHora; // Se ingresa la hora en el evento
    NuevaActividad.NumActividad = ide;  // Se ingresa lo que se obtuvo de la transformacion de ide al  numero de actividad

    struct nodo *NuevoNodoDeActividad = (nodo *) malloc(sizeof(nodo)); //Se crea un nuevo nodo
    NuevoNodoDeActividad -> thisActivity = NuevaActividad;
    NuevoNodoDeActividad -> id = ide;

    enum boolean verificar = add(listActividad, &NuevoNodoDeActividad, &ide);

    MostrarActividad((*listActividad)->thisActivity);

    return verificar;
}

// Funcion que muestra la hora, recibiendo como parametro una estructura de tipo hora
void MostrarHora(Hora thisHora){
    p("\n\tHora: %d : %d", thisHora.Horas, thisHora.minutos);
}

// Funcion que muestra la fecha, recibiendo como parametro una estructura de tipo Fecha
void MostrarFecha(Fecha thisFecha)
{
    p("\n\tFecha: %d / %d / %d", thisFecha.dia , thisFecha.mes, thisFecha.anio);
}

// Aqui hay problemas
// Funcion que muestra una actividad, recibiendo como parametro una estructura de tipo activity
void MostrarActividad(struct activity Evento){

    p("\n\n\tNo. Actividad: %d \t Nombre de la actividad:  ", Evento.NumActividad);
    puts(Evento.NombreActividad);
    p("\n\n\tLugar:");
    puts(Evento.lugar);
    MostrarFecha(Evento.thisFecha);
    MostrarHora(Evento.thisHora);
    p("\n\n\n\tDescripcion:\n\n\t%s\n\t", Evento.descripcion);

}

// Funcion que permite recorrer la lista de actividades e imprimir cada una
enum boolean VerActividades(struct nodo *listActividad)
{

    struct nodo *actual = listActividad;
    int respuesta;

    p("\n\n\tEn la funcion VerActividades");

    if(actual == NULL){
        p("\n\n\tLa lista esta vacia");
        return false;
    }
    else{

        system("cls");

        MostrarActividad(actual->thisActivity);
        respuesta = validar(1, 3, "Elige una opcion\n\n\t(1) Actividad anterior\t\t(2) Salir\t\t(3) Actividad siguiente\n\n\t\t\t: ");
        
        while (respuesta == 1 || respuesta == 3)
        {
            system("cls");
            switch (respuesta){

            case 1:
                actual = actual->anterior;
                break;
            
            case 3:
                actual = actual->siguiente;
                break;
            }

            MostrarActividad(actual->thisActivity);

            respuesta = validar(1, 3, "Elige una opcion\n\n\t(1) Actividad anterior\t\t(2) Salir\t\t(3) Actividad siguiente\n\n\t\t\t: ");
        }
        return true;
    }
}

struct activity BuscarActividad(struct nodo **listaActividad){

    int respuesta , ide;
    struct Hora thisHora;
    struct nodo *busqueda;
    struct activity ActividadBuscada;

    // Inicializamos a la estructura de este modo por si no se encontro, entonces devolver una estructura "vacia", para que despues se valide si hay un NA en sus parametros, entonces no existe o esta vacia la actividad
    ActividadBuscada.NumActividad = 9999;
    ActividadBuscada.NombreActividad = "NA";
    ActividadBuscada.lugar = "NA";
    ActividadBuscada.descripcion = "NA";

    respuesta = validar(1,2, "Elige una opcion\n\n\t(1) Realizar una busqueda\t\t(2)Cancelar busqueda\n\n\t: ");
    while (respuesta == 1 )
    {
        thisHora = PedirLaHora("Ingresa la hora de la actividad que deseas buscar: ");
        ide = (thisHora.Horas * 100) + (thisHora.minutos); // Esto sirve para que el ide de la actividad tenga la hora pero "concatenada y casteada a entero", ejemplo: La hora es 03:11 entonces ide = 311

        busqueda = search(listaActividad, &ide);

        if(busqueda == NULL){ //Si la busqueda devuelve que es nulo entonces no se encontro ningun nodo con la ide ingresada
            p("\n\n\tNo se encontro la actividad");
            respuesta = validar(1, 2, "Elige una opcion\n\n\t(1) Realizar otra busqueda\t\t(2)salir\n\n\t: ");
        }else{
            p("\n\n\tSe encontro la actividad");
            ActividadBuscada = busqueda->thisActivity; // si se encontro la actividad entonces se le asigna a ActividadBuscada para luego retornarla
        }
        
        respuesta = validar(1, 2,"Elige una opcion\n\n\t(1) Realizar otra busqueda\t\t(2)aceptar busqueda\n\n\t: ");
    }

    return ActividadBuscada;
}

void EliminarActividad(struct nodo **listaActividad){

    struct activity thisActivity;
    struct nodo *NodoAEliminar; 
    int respuesta, ide, opcion;
    if(*listaActividad != NULL){
        system("cls");
        respuesta = validar(1, 2, "Elige una opcion\n\n\t(1) Eliminar una actividad\t\t(2)salir\n\n\t: ");
        while (respuesta == 1 || *listaActividad != NULL)
        {
            system("cls");
            thisActivity = BuscarActividad(listaActividad);//Se busca la actividad que se desea eliminar
            ide = (thisActivity.thisHora.Horas * 100) + (thisActivity.thisHora.minutos); // Esto sirve para que el ide de la actividad tenga la hora pero "concatenada y casteada a entero", ejemplo: La hora es 03:11 entonces ide = 311
            NodoAEliminar = search(listaActividad, &ide); //Se busca de nuevo en la lista, pero esta vez se devuelve completamente el nodo

            if (del(listaActividad, &NodoAEliminar)){
                system("cls");
                p("\n\n\tSe elimino correctamente la actividad");
                if(*listaActividad == NULL){
                    system("cls");
                    p("\n\n\tLa lista de actividades se a vaciado completamente");
                    break;
                }
            }    
            else{
                system("cls");
                p("\n\n\t no se pudo eliminar  la actividad");
            }
            system("cls");
            respuesta = validar(1, 2, "Elige una opcion\n\n\t(1) Eliminar otra actividad\t\t(2)salir\n\n\t: ");
            if(respuesta == 2)
                break;
        }
    }
    else{
        system("cls");
        p("\n\n\tLista vacia");
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

            opcion = validar(1, 6, "\n\n\tselecciona la opcion que deseas realizar\n\n\t\t1)Ver Actividades\n\n\t\t2)Agregar actividad\n\n\t\t3)Eliminar una actividad\n\n\t\t4)Buscar una actividad\n\n\t\t5)Salir\n\n\t\t:");
            switch (opcion){
            case 1:

                // Aqui va la funcion ver actividadades // ISSUE HERE
                system("cls");
                p("\n\n\t%s\n\n\t", ((VerActividades((thisDay.listaActividades))) ? "Mostrando actividades" : "No hay actividades que mostrar"));
                system("cls");
                
                break;
            case 2:

                // Aqui va la funcion agregar actividad
                system("cls");
                p("\n\n\t%s\n\n\t", ((AgregarActividad(&(thisDay.listaActividades), fechaDeHoy)) ? "Se agrego la actividad o evento" : "Se cancelo el procesos"));
                system("cls");

                break;

            case 3:

                // Aqui va la funcion eliminar actividad
                system("cls");
                EliminarActividad(&(thisDay.listaActividades));
                system("cls");

                break;
            case 4:

                // Aqui va la funcion buscar actividad
                system("cls");
                MostrarActividad(BuscarActividad(&(thisDay.listaActividades)));
                break;
            case 5:

                //Salir
                p("\n\n\tSaliendo");
                respuesta = 2;

                break;
            }
        }
        
        // opcion = validar(1,);
        
        respuesta = answer("seccion mostrar mi dia"); // se pregunta si se desea ingresar al menu principal o salir
    }
}

