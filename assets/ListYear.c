
// La funcion CreaYear sirve para inicializar un año con todos los 12 meses y su respectivo numero
// el cual se le es asignado directamente del parametro recibido por la misma funcion
// La funcion retorna a la estructura de tipo year 
struct year CrearYear(int anio){

    int i;
    struct year nuevoYear;

    nuevoYear.anio = anio;

    ListarMeses(nuevoYear.listaMeses);

    return nuevoYear;

}

// Funcion que agrega a la lista los 12 meses que requiere un año
void ListarMeses(struct month *ListaMeses){

    int i , j , max;

    
    for(i = 0 ; i < 12 ; i++){

        (ListaMeses + i) -> mes = i+1;
        // p("\n\n\tListaMeses[%d] => %d\n\n", i, (ListaMeses + i)->mes);
        agregarDiasAMeses((ListaMeses + i)-> listaDias, i + 1);
        max = LogicaEnemerarDias(i + 1);

        // for(j = 0 ; j < max ; j++){

        //     p("\n\n\t dia: %d", (ListaMeses + i)->listaDias[j].dia);
        // }

    }

}

// Funcion que crea un nuevo mes y lo guarda en el nodo nuevo de la lista
void agregarDiasAMeses(struct day *ListaDias , int numMes){

    int i;
    int max = LogicaEnemerarDias(numMes);

    // Logica para realizar
    for (i = 0; i < max; i++){
        (ListaDias + i) -> dia = i+1;
        // p("ListaDias[%d] => %d\n", i, ListaDias[i].dia);
    }

}

int LogicaEnemerarDias(int numMes){
    if(numMes == 2)
        return 28;

    else if (numMes == 4 || numMes == 6 || numMes == 9 || numMes == 11)
        return 30;
    
    else return 31;
}

void MostrarTodoElCalendario(struct year anio){

    int i , j , numMaxDias;

    for(i = 0 ; i < 12 ; i++){
        
        numMaxDias = LogicaEnemerarDias(i+1);

        for(j = 0 ; j < numMaxDias ; i++){

            p("\n\n\t%d - %d - %d", anio.listaMeses[i].mes,anio.listaMeses[i].listaDias[j].dia,anio.anio);
            
        }

    }
           
    
}

