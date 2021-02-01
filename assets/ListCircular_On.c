/*
Script donde se alojan todas las funciones del la estructura de datos lista circular
doblemente ligada.
*/

/* 
Esta funcion sirve para buscar nodos a una lista ciruclar doblemente ligada
recibe como parametros a la cabeza de la lista y el ide con el que se va a buscar el nodo, 
la funcion devuelve al nodo encontrado
Complejidad teorica: por tener una sola estructura de control el algoritmo de busqueda es completamente lineal O(n) = n
En el mejor de los casos es cuando el ide a buscar esta en head o que head sea null, es decir que la lista no tenga ningung elemento
Para el peor de los caso es que el ide no este en la lista.
Por ende la complejidad depende directamente del tamaño de la lista 
*/ 
nodo *search(nodo **head, int *ide) 
{
    if (*head == NULL)                      //2
    {
        return NULL;                        
    }
    else 
    {
        nodo *actual = *head;               // 2      
        enum boolean validar = false;       // 2
        do
        {
            if (actual->id == *ide)         //2
            {
                validar = true;             //1
                break;
            }
            else 
            {
                actual = actual->anterior;  //1
            }
        } while (actual != *head);          //n => el ciclo tiene un coste de 3n

        if (validar == true)                //2
        {
            return actual;                  //1
        }
        else
        {
            return NULL;                    //1
        }
    }
}// COMPLEJIDAD REAL:  para el peor de los casos 3n + 8 , para el mejor caso es de 3 si la listas esta vacia, donde n es el tamño de la lista


// Funciones que obtinen el id mas alto y el mas bajo de la lista
/*
Complejidad teorica: La funcion solo tiene una estructura de control por lo que la funcion tiene una complejidad de O(n)  = n para el peor de los casos
y para el mejor de los casos seria cuando la lista solo se tiene un elemento o este vacia
*/
int IdNodoMenor(nodo **head)
{
    int idmin;                                                          //1
    nodo *actual = *head;                                               //2
    if (*head == NULL)                                                  //2
    {
        return 0;   
    }
    else
    {
        if ((*head)->siguiente == *head && (*head)->anterior == *head)  //4
        {
            return (*head)->id;                                         
        }
        else
        {
            do
            {
                idmin = actual->id;                                     //1
                if (idmin > actual->id)                                 //2
                {
                    actual = actual->anterior;                          //1
                }
                else
                {
                    return idmin;                                       //1
                }
            } while (actual != *head);                                  //n  => el ciclo tiene un coste de 5n
        }
    }
} // COMPLEJIDAD REAL:  para el peor de los casos 5n + 9 , para el mejor caso es de 3 si la listas esta vacia, donde n es el tamño de la lista

/*
Complejidad teorica: La funcion solo tiene una estructura de control por lo que la funcion tiene una complejidad de O(n)  = n para el peor de los casos
y para el mejor de los casos seria cuando la lista solo se tiene un elemento o este vacia
*/
int IdNodoMayor(nodo **head) 
{
    int idmax;                                                         //1
    nodo *actual = *head;                                              //2
    if (*head == NULL)                                                 //2
    {
        return 0;
    }
    else
    {
        if ((*head)->siguiente == *head && (*head)->anterior == *head)  //4
        {
            return (*head)->id;
        }
        else
        {
            do
            {
                idmax = actual->id;                                     //1
                if (idmax < actual->id)                                 //2
                {
                    actual = actual->siguiente;                         //1
                }
                else
                {
                    return idmax;                                       //1
                }
            } while (actual != *head);                                  //n  => el ciclo tiene un coste de 5n
        }
    }
} // COMPLEJIDAD REAL:  para el peor de los casos 5n + 9 , para el mejor caso es de 3 si la listas esta vacia, donde n es el tamño de la lista

// Esta funcion sirve para agregar nodos a una lista ciruclar doblemente ligada
// recibe como parametro a la cabeza de la lista, el nodo que se quiere agregar y el ide para validar si no existe en la lista aun , para ahcer que todos los ide's sean unicos e irrepetibles, para facilitar la busqueda
/*
Complejidad : la funcion tiene 2 estrecuturas de control mas las llamadas de las funciones dNodoMenor(head) , IdNodoMayor(head) y search(head, &idMax) pero no estan anidados por lo que para el peor de los casos es O(n) = n , en el mejor de los casos
es que la lista este vacia, por lo que solo es asociar el apuntador de head al nuevo nodo
*/

enum boolean add(nodo **head, nodo **nuevo, int *ide) 
{
    if (*head == NULL) {    //2
        *head = *nuevo; 
        (*head)->anterior = (*head);    
        (*head)->siguiente = (*head);   
        return true;
    }
    else 
    {
        nodo *actual = *head;   //2        
        enum boolean buscar = false;    //2 
        nodo *tmp = *head;  //2          

        
        int idMin;  //1
        idMin = IdNodoMenor(head);  //1+ 5n + 9 = 5n + 10
        int idMax;  //1
        idMax = IdNodoMayor(head); //1+ 5n + 9 = 5n + 10
        nodo *nodoMayor;//1
        nodoMayor = search(head, &idMax);   //1 + 3n + 8 = 3n + 9
        nodo *NodoMenor;    //1
        NodoMenor = search(head, &idMin); //1 + 3n + 8 = 3n + 9

        do
        {
            if (tmp->id == *ide)    //2
            {
                buscar = true;  //2
                break;//1
            }
            else
            {
                tmp = tmp->anterior;    //1
            }
        } while (tmp != *head); //n => el ciclo tiene un coste de 6n

        if (buscar == false)    //2
        {
            nodo *anterior, *siguiente; //2
            if (*ide < actual->id)  //2
            { 
                actual = actual->anterior;  //1
                anterior = actual->anterior; //1
                siguiente = actual->siguiente; //1

                while (*ide < actual->id && *ide < anterior->id) //n => el ciclo tiene un coste de 8n
                {
                    actual = actual->siguiente; //1
                    anterior = actual->anterior;//1
                    siguiente = actual->siguiente;//1

                    if (actual == *head || anterior == nodoMayor)//4
                    {
                        break; //1
                    }
                }
            }

            else if (*ide > actual->id) 
            {
                actual = actual->siguiente;
                anterior = actual->anterior;
                siguiente = actual->siguiente;

                while (*ide > actual->id && *ide > siguiente->id)
                {
                    actual = actual->siguiente;
                    anterior = actual->anterior;
                    siguiente = actual->siguiente;

                    if (actual == *head || siguiente == NodoMenor)
                    {
                        break;
                    }
                }
            }

            if (*ide > actual->id) //2
            {

                (*nuevo)->anterior = actual; //1
                (*nuevo)->siguiente = siguiente; //1
                siguiente->anterior = (*nuevo); //1
                actual->siguiente = (*nuevo); //1
            }
            else 
            {
                (*nuevo)->siguiente = actual;
                (*nuevo)->anterior = anterior;
                anterior->siguiente = (*nuevo);
                actual->anterior = (*nuevo);
            }
            return true; //1
        }
        else
        {
            return false;
        }
    }
}//Complejidad real: el algoritmo tiene una complejidad para el peor de los casos de 24n + 38 donde la n es el tamaño de la lista, para el mejor de los casos es de 6

// Esta funcion sirve para eliminar nodos a una lista circular doblemente ligada
// Recibe como parametros la cabeza de la lista y el nodo que se quiere eliminar
// dependiendo del caso se compara el nodo y si resulta que coincide con el nodo elegido para eliminar, entonces se procede a eliminar
// moviendo todos los pauntadores de siguiente y anterior para que finalmente el nodo a eliminar quede aislado y despues se force a que apunte a nulo
/*
Complejidad teorica: la funacion tiene solo una estructura de control por lo que la complejidad O(n) = n
Para el mejor de los casos es que la lista este vacia o el nodo que se busca eliminar sea nulo 
*/
enum boolean del(nodo **head, nodo **elegido) 
{
    if (*head != NULL && *elegido != NULL) //4
    {
        nodo *tail = (*head)->siguiente;   //2                                                          
        if ((*elegido)->anterior == *elegido && (*elegido)->siguiente == *elegido && *elegido == *head) //6
        {
            *head = NULL;
            *elegido = NULL;
        }
        else if ((*elegido)->siguiente == tail) //2
        {
            *head = (*head)->anterior;
            tail->anterior = *head;
            (*head)->siguiente = tail;
            (*elegido)->anterior = NULL;
            (*elegido)->siguiente = NULL;
            *elegido = NULL;
        }
        else if (*elegido == tail && (*elegido)->anterior == *head) //4
        {
            tail = tail->siguiente;
            tail->anterior = (*head);
            (*head)->siguiente = tail;
            (*elegido)->siguiente = NULL;
            (*elegido)->anterior = NULL;
            (*elegido) = NULL;
        }
        else 
        {
            nodo *tmp = *head;  //2
            nodo *atras = NULL; //2
            nodo *adelante = NULL;//2
            while (tmp != NULL)   //n => el ciclo tiene un coste de 4n
            {
                if (tmp == *elegido) //2
                {
                    break; //1
                }
                else
                {
                    tmp = tmp->anterior; //1
                }
            }
            atras = tmp->siguiente; //1
            adelante = tmp->anterior; //1
            atras->anterior = adelante; //1
            tmp->siguiente = NULL;      //1
            adelante->siguiente = atras; //1
            tmp->anterior = NULL;        //1
            tmp = NULL;                  //1
            (*elegido) = NULL;           //1
        }
        return true; //1
    }
    else
    {
        return false; 
    }
}//Complejidad real del algoritmo para el peor de los casos es de 4n + 33 tal que n es el tamaño de la lista y el nodo a eliminar es distinto de head, el tamaño de la lista es mayor a 2 nodos y el nodo a eliminar es distinto al nodo o el siguiente de head y para el mejor de los casos es 5

// Esta funcion sirve para contar todos los nodos de una lista circuclar doblemente ligada
// Recibe como parametros el apuntador de la primera localidad de la lista y devulve un contador el cual se incrementa en funcion
// del recorrido de la lista con ayuda del apuntador actual, el cual se va desplazar hacia el nodo anterior hasta el nodo actual sea otra vez la cabeza de la lista
/*
Complejidad teorica: El algoridmo solo tiene una estructura de control la cual depende directamente del tamaño de la lista por lo tanto en terminos de O(n) = n
Para el mejor de los casos es que la lista este vacia
*/
int CountNodes(nodo **head)
{

    int cont = 0; //2
    nodo *actual = *head; //2
    if (*head == NULL)    //2
        return 0;

    do
    {

        cont++; //2
        actual = actual->anterior; //1

    } while (actual != *head); //n => el ciclo tiene un coste de 3n

    return cont; //1
}//Complejidad real: para el peor de los casos es cuando la lista tiene n elementos a contar o sea de 3n + 7 y para el mejor de los casos es de 7 , cuando la lista esta vacia
