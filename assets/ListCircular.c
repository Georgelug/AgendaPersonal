/*
Script donde se alojan todas las funciones del la estructura de datos lista circular
doblemente ligada.
*/

// Esta funcion sirve para agregar nodos a una lista ciruclar doblemente ligada
// recibe como parametro a la cabeza de la lista, el nodo que se quiere agregar y el ide para validar si no existe en la lista aun , para ahcer que todos los ide's sean unicos e irrepetibles, para facilitar la busqueda
enum boolean add(nodo **head, nodo **nuevo, int *ide)
{
    if (*head == NULL) //1er caso si la lista esta vacia entonces solo se asigna la cabeza de la lista al nuevo nodo y hacemos que tanto anterior como  siguiente apunten a head por ende al nuevo nodo (un auto apuntamiento por atras y por adelante)
    {
        *head = *nuevo;
        (*head)->anterior = (*head);
        (*head)->siguiente = (*head);
        return true;
    }
    else // en caso contrario
    {
        nodo *actual = *head; //declaramos a un nodo que apunte a lo que apunta head
        enum boolean buscar = false; // declaramos una variable que nos ayude a notificar si el ide existe ya
        nodo *tmp = *head;           // declaramos otro nodo que apunte a lo que apunta head
        
        //se procede a recorrer la lista en caso de que el ide existe ya entonces buscar es igual a null, mientras no sea tmp otra vez head
        do
        {
            if (tmp->id == *ide)
            {
                buscar = true;
                break;
            }
            else
            {
                tmp = tmp->anterior;
            }
        } while (tmp != *head);
        // en caso de que el ide no este entonces se procede a agregar el nodo
        if (buscar == false)
        {
            nodo *anterior , *siguiente;
            if(*ide < actual->id)
            { //Primer caso:  cuando El ide de nuevo es menor de actual entonces se recorre hacia el anterior hasta que el ide sea menor
                actual = actual -> anterior;
                anterior = actual->anterior;
                siguiente = actual -> siguiente;

                while (*ide < actual->id && *ide < anterior -> id)// se recorre hacia los nodos anteriores de actual
                {
                    actual = actual->siguiente;
                    anterior = actual->anterior;
                    siguiente = actual->siguiente;

                    if (actual == *head)
                    {
                        break;    
                    }
                }
            }

            else if (*ide > actual->id) // segundo caso: cuando El ide de nuevo es mayor de actual entonces se recorre hacia el siguiente hasta que el ide sea mayor
            {
                actual = actual->siguiente;
                anterior = actual->anterior;
                siguiente = actual->siguiente;

                while (*ide > actual->id && *ide > siguiente->id)
                {
                    actual = actual->siguiente;
                    anterior = actual->anterior;
                    siguiente = actual->siguiente;

                    if (actual == *head)
                    {
                        break;
                    }
                }
            }

            if(*ide > actual-> id )// se ingresa el nodo al siguiente del actual
            {
                
                (*nuevo) -> anterior = actual;
                (*nuevo) -> siguiente = siguiente;
                siguiente -> anterior = (*nuevo);
                actual -> siguiente = (*nuevo);

            }
            else // se ingresa el nodo al anterior del actual
            {
                (*nuevo)->siguiente = actual;
                (*nuevo)->anterior = anterior;
                anterior->siguiente = (*nuevo);
                actual->anterior = (*nuevo);
            }

            /*
            actual = actual->siguiente; // el
            actual->anterior = *nuevo;
            (*nuevo)->siguiente = actual;
            actual = actual->anterior;
            actual->anterior = *head;
            (*head)->siguiente = actual;
            */

            return true;
        }
        else
        {
            return false;
        }
    }
}

// Esta funcion sirve para buscar nodos a una lista ciruclar doblemente ligada
//recibe como parametros a la cabeza de la lista y el ide con el que se va a buscar el nodo, la funcion devuelve al nodo encontrado
nodo *search(nodo **head, int *ide)
{
    if (*head == NULL) //en caso de que la lista este vacia, entonces se retorna nulo
    {
        return NULL;
    }
    else//en caso contrario, entonces la lista tiene al menos un nodo
    {
        nodo *actual = *head; // se declara un apuntador asignandole lo que aopunta head
        enum boolean validar = false; // se declara una variable de tipo booleanda para verificar y validar operaciones
        // Se procede a recorrer la lista por medio de el nodo actual hacia el anterio nodo 
        do
        {
            if (actual->id == *ide) // en caso de que el ide sea igual entonce encontro por lo tanto validar notifica que se realizo una operacion y se quiebra el ciclo
            {
                validar = true;
                break;
            }
            else // encaso contrario se sigue recorriendo hacia el nodo anterior
            {
                actual = actual->anterior;
            }
        } while (actual != *head);//se reciorre mienttras actual no sea de nuevo head

        //como se ve validar solo se hace true cuando se encuntra el nodo, entonces se retorna el nodo , encaso contrario retorna nulo por que entonces no se encontro nada
        if (validar == true)
        {
            return actual;
        }
        else
        {
            return NULL;
        }
    }
}

// Esta funcion sirve para eliminar nodos a una lista circular doblemente ligada
// Recibe como parametros la cabeza de la lista y el nodo que se quiere eliminar
// dependiendo del caso se compara el nodo y si resulta que coincide con el nodo elegido para eliminar, entonces se procede a eliminar 
// moviendo todos los pauntadores de siguiente y anterior para que finalmente el nodo a eliminar quede aislado y despues se force a que apunte a nullo
enum boolean del(nodo **head, nodo **elegido)
{
    if (*head != NULL && *elegido != NULL)//se verifica si la lista no esta vacia y elegido tambien
    {
        nodo *tail = (*head)->siguiente;//Se declara otro apuntador al ultimo nodo antes de que este sea head de nuevo por fines practicos
        if ((*elegido)->anterior == *elegido && (*elegido)->siguiente == *elegido && *elegido == *head)//1er caso: la lista solo contiene un solo nodo y ese nodo coincide con el nodo elegido, entonces solo se hace apunte a nullo ambos
        {
            *head = NULL;
            *elegido = NULL;
        }
        else if ((*elegido)->siguiente == tail)// 2do caso: cuando el nodo a eliminar es la cabeza, entonces se procede a recorrer a head hacia el nodo anterior y ahora el siguiente de head sera tail y tail a head y elegido hacemos que apunte a nullo, por ende se elimina
        {
            *head = (*head)->anterior;
            tail->anterior = *head;
            (*head)->siguiente = tail;
            (*elegido)->anterior = NULL;
            (*elegido)->siguiente = NULL;
            *elegido = NULL;
        }
        else if (*elegido == tail && (*elegido)->anterior == *head)//3er caso: cuando solo hayo dos nodos en la lista y el nodo a eliminar resulta que es tail, entonces se procede a hacer quue tail se desplace a head y hacemos que tanto siguiente como anterio apunten tail , asi mismo, por ende , queda con que la lista solo es un nodo el es la cabeza
        {
            tail = tail->siguiente;
            tail->anterior = (*head);
            (*head)->siguiente = tail;
            (*elegido)->siguiente = NULL;
            (*elegido)->anterior = NULL;
            (*elegido) = NULL;
        }
        else//Cualquier otro caso:
        {
            nodo *tmp = *head;// se declara un nodo que apunte a lo que apunta head
            nodo *atras = NULL;//Se declaran dos nodos que representaran a anterior y siguiente
            nodo *adelante = NULL;
            while (tmp != NULL) //Se desplaza a tmp hacia el nodo anterior mientras este no se nulo, en caso de que tmp sea igual a elegido, entonces se rompe ciclo por que ya se desplazo hasta el nodo que se desea eliminar
            {
                if (tmp == *elegido)
                {
                    break;
                }
                else
                {
                    tmp = tmp->anterior;
                }
            }
            atras = tmp->siguiente; // se asigna al apuntador atras al nodo siguiente de tmp
            adelante = tmp->anterior; //se asigna a apuntador adelante al nodo anterior de tmp
            atras->anterior = adelante; // hacemos que ahora el nodo anterior a atras apunte al apuntador adelante
            tmp->siguiente = NULL; //el nodo elegido hacemos que siguiente sea nulo
            adelante->siguiente = atras; //hacemos que el nodo siguiente del apuntador adelante ahora apunte al apuntador atras
            tmp->anterior = NULL; //hacemos que el anterior de tmp apunte a nulo
            tmp = NULL;// finalmente, una vez que tmp queda aislado, es decir tanto anterior como siguiente apuntan a nulo, entonces se procede a eliminarlo , haciendo que apunto a nulo el propio apuntador
            (*elegido) = NULL; // elegido ya no nos sirve por ende tambien se hace que apunte a nulo
        }
        return true; // como se realizaron cambios la funcion devuelve  verdadero, notificando que se realizo bien la operacion
    }
    else
    {
        return false; // en caso que la lista haya estado vacia o el nodo a eliminar no esta en la lista entonces no se relizo ninguna operacion, por ende la funcion devuelve falso notificando que no hizo nada 
    }
}

// Esta funcion sirve para contar todos los nodos de una lista circuclar doblemente ligada
// Recibe como parametros el apuntador de la primera localidad de la lista y devulve un contador el cual se incrementa en funcion
// del recorrido de la lista con ayuda del apuntador actual, el cual se va desplazar hacia el nodo anterior hasta el nodo actual sea otra vez la cabeza de la lista
int CountNodes(nodo **head){

    int cont = 0;
    nodo *actual = *head;
    if(*head == NULL)
        return 0;

    do{

        cont++;
        actual = actual -> anterior;

    }while(actual != *head);

    return cont;
}

int IdNodoMenor(nodo **head){
    int idmin;
    nodo *actual = *head;
    if(*head == NULL)//Lista vacia
    {
        return 0;
    }
    else{
        if ((*head)->siguinete == *head && (*head)->anterior == *head){
            return (*head) -> id ;
        }else{
            do
            {
               idmin = actual->id;
               if (idmin > actual->id){
                   actual = actual->anterior;
               }else{
                   return idmin;
               }
            } while (actual != *head);
            
        }
    }
}

int IdNodoMayor(nodo **head){
    int idmax;
    nodo *actual = *head;
    if (*head == NULL) //Lista vacia
    {
        return 0;
    }
    else
    {
        if ((*head)->siguinete == *head && (*head)->anterior == *head)
        {
            return (*head)->id;
        }
        else
        {
            do
            {
                idmax = actual->id;
                if (idmax < actual->id)
                {
                    actual = actual->siguiente;
                }
                else
                {
                    return idmin;
                }
            } while (actual != *head);
        }
    }
}