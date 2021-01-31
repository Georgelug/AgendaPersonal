// Funcion que recibe como parametros 
struct Fecha PedirLaFecha(char *frase,int anio){
    struct Fecha nuevaFecha;

    system("cls");
    p("\n\n\t%s", frase);

    nuevaFecha.mes = validar(1, 12, "Ingresa el mes (de 1 a 12): ");
    nuevaFecha.dia = validar(1, 31, "Ingresa el dia (de 1 a 31): ");
    nuevaFecha.anio = anio;

    system("cls");

    return nuevaFecha;
}

// Funcion que regresa el dia del anio dada una fecha
struct day BuscarDia(struct Fecha thisFecha, struct year thisAnio){
    return thisAnio.listaMeses[thisFecha.mes -1].listaDias[thisFecha.dia - 1];
}

// Funcion que muestra el menu que permite buscar un avento a partir de una fecha en especifico y no el dia de hoy
void menuBuscarEvento(struct year *anio){

    int respuesta, opcion;
    struct activity ActividadBuscada;
    struct Fecha thisFecha;
    struct day thisDia;

    system("cls");
    respuesta = validar(1, 2, "Elige una opcion\n\n\t(1) Realizar una busqueda\t\t(2)Cancelar busqueda\n\n\t: ");
    while (respuesta == 1){

        thisFecha = PedirLaFecha("Ingresa la Fecha que desea buscar: ",anio->anio);
        thisDia = BuscarDia(thisFecha , *anio);

        menuDiaBuscado(&thisDia , thisFecha);
        anio->listaMeses[thisFecha.mes-1].listaDias[thisFecha.dia-1] = thisDia;
        respuesta = validar(1, 2, "Elige una opcion\n\n\t(1) Realizar una busqueda\t\t(2)Cancelar busqueda\n\n\t: ");
    }
}