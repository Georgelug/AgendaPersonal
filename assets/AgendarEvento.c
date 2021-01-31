
// Funcion que despliega las opciones y todo para agendar
void menuAgendarEvento(struct year *anio)
{
    int respuesta, opcion;
    struct activity ActividadBuscada;
    struct Fecha thisFecha;
    struct day thisDia;

    system("cls");
    respuesta = validar(1, 2, "Elige una opcion\n\n\t(1) Agregar un evento \t\t(2)salir\n\n\t: ");
    while (respuesta == 1)
    {
        system("cls");

        thisFecha = PedirLaFecha("Ingresa la Fecha del evento que deseas agregar: ", anio->anio);
        thisDia = BuscarDia(thisFecha, *anio);

        if(AgregarActividad(&(thisDia.listaActividades) , thisFecha))
            p("\n\n\tSe agrego el evento con exito");
        else
            p("\n\n\tError, no se pudo agregar el evento");

        anio->listaMeses[thisFecha.mes - 1].listaDias[thisFecha.dia - 1] = thisDia;

        respuesta = validar(1, 2, "Elige una opcion\n\n\t(1) Agregar otro evento \t\t(2)salir\n\n\t: ");
    }
}