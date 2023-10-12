#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funciones.h"

int main() {
    int cantidaddearticulos = 0;

    printf("Ingrese la cantidad de artículos que quiere agregar: ");
    scanf("%d", &cantidaddearticulos);

    char caracteresnovacios[cantidaddearticulos][100];
    int guardarcaracteresnovacios[cantidaddearticulos];
    char **guardararticulos = (char **)calloc(cantidaddearticulos, sizeof(char *));
    float *guardarprecios = (float *)calloc(cantidaddearticulos, sizeof(float));

    for (int i = 0; i < cantidaddearticulos; i++) {
        *(guardararticulos + i) = (char *)calloc(cantidaddearticulos, sizeof(char));
    }

    // Parte para agregar nuevos artículos

    agregarArticulos(cantidaddearticulos, guardarcaracteresnovacios, guardarprecios, guardararticulos, caracteresnovacios);

    // Parte para imprimir/mostrar artículos:

    printf("|\tArtículos\t|\t|\t Precios \t|\n");
    printf("|-----------------------|\t|-----------------------|\n");

    imprimirArticulos(cantidaddearticulos, guardarcaracteresnovacios, guardararticulos, guardarprecios);

    int arregloparasabercuantosquiso[100];
    char comprobarsiquiere[5][100];
    float dineroconelcualpaga = 0;

    contarArticulos(cantidaddearticulos, arregloparasabercuantosquiso, comprobarsiquiere, guardarprecios);

    /*
    Guardamos cuantos quiso de cual, llamamos al puntero y usamos los valores para hacer la conversión en dinero de cuanto es, en total,
    necesitamos al puntero donde guardamos el precio del artículo, la cantidad de articulos de ese artículo para multiplicar su valor y
    el arreglo de selección para la ubicación del precio en el puntero. */

    /*  float *arregloparaguardarlospreciosydespuesumarlos = (float*)calloc(i, sizeof(float));

     for (int j = 0; j < i; j++)
     {
        *(arregloparaguardarlospreciosydespuesumarlos + j) = (*(guardarprecios + arregloparaselecciondearticulo[j])) * arregloparasabercuantosquiso[j];
         printf("Precio total del articulo no. %d seleccionado: %.2f\n", j+1, *(arregloparaguardarlospreciosydespuesumarlos+j));
     }  */

    // Parte para cobrar al cliente y generar el recibo:
    // Parte para cobrar al cliente y generar el recibo:

    // Parte para cobrar al cliente y generar el ticket de venta:
    imprimirTicket(cantidaddearticulos, arregloparasabercuantosquiso, guardararticulos, guardarprecios, caracteresnovacios);
}
