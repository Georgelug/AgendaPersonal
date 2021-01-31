int LogicaEnemerarDias(int numMes)
{
    if (numMes == 2)
        return 28;

    else if (numMes == 4 || numMes == 6 || numMes == 9 || numMes == 11)
        return 30;

    else
        return 31;
}

// Funcion que crea un nuevo mes y lo guarda en el nodo nuevo de la lista
void agregarDiasAMeses(struct day *ListaDias, int numMes)
{

    int i;
    int max = LogicaEnemerarDias(numMes);

    // Logica para realizar
    for (i = 0; i < max; i++)
    {
        (ListaDias + i)->dia = i + 1;
    }
}

// Funcion que agrega a la lista los 12 meses que requiere un año
void ListarMeses(struct month *ListaMeses){

    int i , j , max;
    
    for(i = 0 ; i < 12 ; i++){
        (ListaMeses + i) -> mes = i+1;
        agregarDiasAMeses((ListaMeses + i)-> listaDias, i + 1);
        max = LogicaEnemerarDias(i + 1);
    }

}

// La funcion CreaYear sirve para inicializar un año con todos los 12 meses y su respectivo numero
// el cual se le es asignado directamente del parametro recibido por la misma funcion
// La funcion retorna a la estructura de tipo year
struct year CrearYear(int anio)
{
    
    struct year nuevoYear;

    nuevoYear.anio = anio;

    ListarMeses(nuevoYear.listaMeses);

    return nuevoYear;
}



void MostrarTodoElCalendario(struct year anio){

    int i , j , numMaxDias;

    for(i = 0 ; i < 12 ; i++){
        
        numMaxDias = LogicaEnemerarDias(i+1);

        for(j = 0 ; j < numMaxDias ; j++){

            p("\n\n\t%d - %d - %d", anio.listaMeses[i].mes,anio.listaMeses[i].listaDias[j].dia,anio.anio);
            
        }

    }
           
    
}

// Funcion que sirve para agregar a la lista anios el nodo del nuevo anio ademas de asignarle a ese nodo la estructura de tipo Year
enum boolean agregarNuevoAnioAListaDeAnios(struct nodo **YearLista, int IdeAnio, struct year anioNuevo)
{

    struct nodo *nuevoAnio_nuevoNodo = (nodo *)malloc(sizeof(nodo)); //Se crea un nuevo nodo
    nuevoAnio_nuevoNodo->thisYear = anioNuevo; // se le asigna la estructura como tal de tipo anio
    nuevoAnio_nuevoNodo->id = IdeAnio; // Se agrega el ide  que con ese se buscara en la lista, en esta caso sera 2021, en caso de sea el mismo anio no abra de agregarlo por lo que la funcion retornara false

    return add(YearLista, &nuevoAnio_nuevoNodo, &IdeAnio);
}

struct year getYearFromListOfNodes(struct nodo **YearLista, int IdeAnio){

    return search(YearLista , &IdeAnio) -> thisYear;

}


