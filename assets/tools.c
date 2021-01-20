

// Funcion que sirve para validar respuestas para continuar o salir de la seccion, recibe el nombre de la seccion en el que se este del programa ejemplo: menu 
// en caso de que el valor leido sea menor que 1 o mayor que 2, entonces marcara error y seguirá pidiendo el valor hasta que sea el correcto y hasta entonces retornara el valor ya sea 1 o 2
int answer(char seccion[10]){
    int respuesta;
    p("\n\n\tPresiona (1)Entrar/continuar en %s (2)salir de %s \n\n\t:  ", seccion, seccion);
    s("%d", &respuesta);
    while (respuesta < 1 || respuesta > 2)
    {
        p("\n\n\tERROR, Presiona (1)continuar en %s (2)salir de %s \n\n\t:  ", seccion, seccion);
        s("%d", &respuesta);
    }
    return respuesta;
}

// Funcion que sirve para validar respuestas para continuar o salir de la seccion, recibe un menu especifico en el que se desea ciertos valores, en caso de que lo leido sea menor al min y/o sea mayor que max entonces
// marcara error y seguirá pidiendo el valor hasta que sea el correcto y hasta entonces retornara el valor
int validar(int min, int max, char *string){
    int op;
    p("\n\n\t%s", string);//Menu especifico
    s("%d", &op);
    while (op < min || op > max)
    {
        p("\n\n\tERROR, intentalo de nuevo\n\n\t%s", string);
        s("%d", &(op));
    }

    return op;
}

