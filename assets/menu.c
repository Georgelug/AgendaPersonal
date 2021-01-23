void menu(){
    // variables de la funcion
    int respuesta;
    int opcion;
    
    struct year anioNuevo;

    struct nodo *YearLista = NULL;

    system("cls");

    respuesta = answer("Menu principal");
    while(respuesta == 1){
        system("cls");
        opcion = validar(1,4,"\n\n\tSaludos, selecciona la opcion que deseas realizar\n\n\t1)Ver mi dia\n\t2)Buscar evento\n\t3)Agendar evento\n\n\t4)Salir\n\n\t:");
        
        switch (opcion){
        case 1:
            // Ver mi dia
            system("cls");
            p("\n\n\tVer mi dia");

            anioNuevo = CrearYear(2021);
            MostrarTodoElCalendario(anioNuevo);

            break;
        case 2:
            // Buscar evento
            system("cls");
            p("\n\n\tBuscar evento");

            break;
        case 3:
            // Agendar evento
            system("cls");
            p("\n\n\tAgendar evento");
            break;
        case 4:
            // Salir
            system("cls");
            p("\n\n\tSalir");
            respuesta = 2;

            break;
        }
        respuesta = answer("Menu principal");
    }


}