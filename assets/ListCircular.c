/*
Script don se alojan todas las funciones del la estructura de datos lista circular
doblemente ligada.
*/

enum boolean add(nodo **head, nodo **nuevo, int *ide)
{
    if (*head == NULL)
    {
        *head = *nuevo;
        (*head)->anterior = (*head);
        (*head)->siguiente = (*head);
        return true;
    }
    else
    {
        nodo *actual = *head;
        enum boolean buscar = false;
        nodo *tmp = *head;
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
        if (buscar == false)
        {
            actual = actual->siguiente;
            actual->anterior = *nuevo;
            (*nuevo)->siguiente = actual;
            actual = actual->anterior;
            actual->anterior = *head;
            (*head)->siguiente = actual;
            return true;
        }
        else
        {
            return false;
        }
    }
}
nodo *search(nodo **head, int *ide)
{
    if (*head == NULL)
    {
        return NULL;
    }
    else
    {
        nodo *actual = *head;
        enum boolean validar = false;
        do
        {
            if (actual->id == *ide)
            {
                validar = true;
                break;
            }
            else
            {
                actual = actual->anterior;
            }
        } while (actual != *head);
        //((validar == true) ? return actual : return NULL);//aqui
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
enum boolean del(nodo **head, nodo **elegido)
{
    if (*head != NULL && *elegido != NULL)
    {
        nodo *tail = (*head)->siguiente;
        if ((*elegido)->anterior == *elegido && (*elegido)->siguiente == *elegido && *elegido == *head)
        {
            *head = NULL;
            *elegido = NULL;
        }
        else if ((*elegido)->siguiente == tail)
        {
            *head = (*head)->anterior;
            tail->anterior = *head;
            (*head)->siguiente = tail;
            (*elegido)->anterior = NULL;
            (*elegido)->siguiente = NULL;
            *elegido = NULL;
        }
        else if (*elegido == tail && (*elegido)->anterior == *head)
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
            nodo *tmp = *head;
            nodo *atras = NULL;
            nodo *adelante = NULL;
            while (tmp != NULL)
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
            atras = tmp->siguiente;
            adelante = tmp->anterior;
            atras->anterior = adelante;
            tmp->siguiente = NULL;
            adelante->siguiente = atras;
            tmp->anterior = NULL;
            tmp = NULL;
            (*elegido) = NULL;
        }
        return true;
    }
    else
    {
        return false;
    }
}

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