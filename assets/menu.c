// Esta funcion es el menu principal, el cual muestra en pantalla las acciones disponibles que puede hacer usuario.
void menu()
{
    // variables de la funcion
    int respuesta; // varible de desicion para ingresar o salir a menu principal
    int opcion; // variable de seleccion de opciones mostradas en pantalla al usuario
    
    // estructura de la biblioteca windows.h para obtener el tiempo del sistema
    SYSTEMTIME tempo;     //Se declara la estructura SYSTEMTIME tempo
    GetLocalTime(&tempo);     //Funcion que recibe una estructura SYSTEMTIME tempo y le asigna a los parametros de tempo las horas, minutos,segundos, el dia, el mes y el anio

    // Estructura Fecha que obtiene de Tempo , la fecha de hoy
    struct Fecha fechaDeHoy;
    fechaDeHoy.dia = tempo.wDay;
    fechaDeHoy.mes = tempo.wMonth;
    fechaDeHoy.anio = tempo.wYear;

    // Estrcutura Hora que obtiene de tempo la hora exacta en el instante  en que se obtiene la informacion
    struct Hora tiempoDeahora;
    tiempoDeahora.Horas = tempo.wHour;
    tiempoDeahora.minutos = tempo.wMinute;

    struct year anioNuevo = CrearYear(fechaDeHoy.anio); // estructura donde se almacena el anio 2021
    struct nodo *YearLista = NULL; //Apuntador a la primera localidad del la lista donde van a ir almacenandose los anios
    enum boolean verificarListaDeAnios = agregarNuevoAnioAListaDeAnios(&YearLista , fechaDeHoy.anio , anioNuevo);
    anioNuevo = getYearFromListOfNodes(&YearLista, fechaDeHoy.anio); // Ahora se busca el nodo agregado y se le asigna a esta estructura, la estructura de tipo year guardado previamente en el nodo de la lista cuyo ide es el anio en curso
    
    system("cls");// se limpia pantalla
    
    respuesta = answer("Menu principal"); // se pregunta si se desea ingresar al menu principal o salir 
    while(respuesta == 1){

        // En caso de que sea respuesta = 1 entonces se ingresa al ciclo while y dentro de este ciclo se muestran a elegir 4 opciones
        //Lo cual dependiendo de la opcion se manda a llamar su respectiva funcion 
        system("cls");
        opcion = validar(1,4,"\n\n\tSaludos, selecciona la opcion que deseas realizar\n\n\t1)Ver mi dia\n\t2)Buscar evento\n\t3)Agendar evento\n\n\t4)Salir\n\n\t:");
        
        switch (opcion){
        case 1:
            // Ver mi dia
            system("cls");

            menuMiDia(anioNuevo , fechaDeHoy , tempo);

            break;
        case 2:
            // Buscar evento
            system("cls");
            menuBuscarEvento(&anioNuevo);

            break;
        case 3:
            // Agendar evento
            system("cls");
            menuAgendarEvento(&anioNuevo);
            break;
        case 4:
            // Salir
            system("cls");
            p("\n\n\tSalir");
            respuesta = 2;
            break;
        }

        system("cls");
        if(respuesta != 2)
            respuesta = answer("Menu principal"); //se vuelve a preguntar por si se requiere continuar en el menu princiapl o salir del programa
    }
}
