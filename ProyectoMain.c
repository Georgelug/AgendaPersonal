
// Bibliotecas estandar y definiciones
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
    struct activity *listaDias;

} day;

typedef struct month
{
    // Atributos de la estructura month
    int mes;
    struct month *listaDias;

} month;

typedef struct year
{
    // Atributos de la estructura year
    int anio;
    struct month *listaMeses;

} year;

//Nodos de lista circular doblemente ligada
typedef struct nodo
{
    // Atributos del nodo
    int id;
    struct nodo *next;
    struct nodo *before;

    // Para cada nodo tendran los 4 tipos de estructuras (year, month, day, activity)
    struct year thisYear;
    struct month thisMonth;
    struct day thisDay;
    struct activity thisActivity;

} nodo;
// assets
#include "assets\tools.c"
#include "assets\menu.c"


// funcion main
int main(void){

    menu(); //Funcion que muestra el menu principal

    return 0;

}