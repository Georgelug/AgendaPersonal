
// Bibliotecas estandar y definiciones
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Definiciones y constantes
// definimos p y s como printf para optimizar al momento de codificar
#define p printf 
#define s scanf
enum boolean { false , true }; // constantes booleanas que sirven para emplear el uso de false y true, y sea mas intuitivo para saber si devuelve falso o verdadero una funcion o para asignarlo en variables

// Estructuras

// Estructuras de la agenda
typedef struct Hora{

    int Horas;
    int minutos;

}Hora;

typedef struct Fecha{
    int anio;
    int mes;
    int dia;
}Fecha;

typedef struct activity
{
    // Atributos de la estructura activity
    int NumActividad;
    char *NombreActividad;
    char *lugar;
    char *descripcion;

    struct Hora thisHora;
    struct Fecha thisFecha;

} activity;

typedef struct day
{
    // Atributos de la estructura day
    int dia;
    struct nodo *listaActividades ;

} day;

typedef struct month
{
    // Atributos de la estructura month
    int mes;
    struct day listaDias[31];

} month;

typedef struct year
{
    // Atributos de la estructura year
    int anio;
    struct month listaMeses [12];

} year;

//Nodos de lista circular doblemente ligada
typedef struct nodo
{
    // Atributos del nodo
    int id;
    struct nodo *siguiente;
    struct nodo *anterior;


    struct activity thisActivity;
    struct year thisYear;

} nodo;


// assets, todos scripts incluidos , que requiere el programa para su funcionamiento
#include "assets\tools.c"
#include "assets\ListCircular.c"
#include "assets\MiDia.c"
#include "assets\BuscarEvento.c"
#include "assets\AgendarEvento.c"
#include "assets\Listyear.c"
#include "assets\menu.c"


// funcion main
int main(void){

    menu(); //Funcion que muestra el menu principal

    return 0;

}
