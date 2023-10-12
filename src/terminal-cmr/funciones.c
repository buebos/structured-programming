#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void agregarArticulos(int cantidaddearticulos, int* guardarcaracteresnovacios, float* guardarprecios, char** guardar_articulos, char caracteresnovacios[][100]) {
    for (int i = 0; i < cantidaddearticulos; i++) {
        printf("Ingrese el artículo %d: ", i + 1);
        scanf("%s", caracteresnovacios[i]);
        guardarcaracteresnovacios[i] = strlen(caracteresnovacios[i]);
        printf("Ingrese el precio del artículo %d: ", i + 1);
        scanf("%f", guardarprecios + i);
    }

    for (int i = 0; i < cantidaddearticulos; i++) {
        for (int j = 0; j <= guardarcaracteresnovacios[i]; j++) {
            *(*(guardar_articulos + i) + j) = caracteresnovacios[i][j];
        }
    }
}

void imprimirArticulos(int cantidaddearticulos, int* guardarcaracteresnovacios, char** guardar_articulos, float* guardarprecios) {
    for (int i = 0; i < cantidaddearticulos; i++) {
        /* guardarcaracteresnovacios[i]; */

        printf("| [%d]\t", i + 1);
        for (int j = 0; j <= guardarcaracteresnovacios[i]; j++) {
            printf("%c", *(*(guardar_articulos + i) + j));
        }

        if (guardarcaracteresnovacios[i] <= 6) {
            printf(" \t\t|");
        } else {
            printf(" \t|");
        }

        printf("\t|\t$%.2f MXN \t|\n", *(guardarprecios + i));
    }
}

void contarArticulos(int cantidaddearticulos, int* arregloparasabercuantosquiso, char comprobarsiquiere[5][100], float* guardarprecios) {
    int i = 0;
    int j = 0;
    bool yanoquierearticulos = false;
    float dineroconelcualpaga = 0;
    int arregloparaselecciondearticulo[100];

    while (yanoquierearticulos == false && i <= 100) {
        printf("Seleccione el artículo necesitado: ");
        scanf("%d", &arregloparaselecciondearticulo[i]);
        if (arregloparaselecciondearticulo[i] < 0 || arregloparaselecciondearticulo[i] > cantidaddearticulos) {
            printf("Ingrese una selección válida.\n");
            i--;
        } else {
            printf("¿Cuántos necesita?: ");
            scanf("%d", &arregloparasabercuantosquiso[i]);
        }

        printf("Quiere seguir agregando artículos(Sí/No)?:");
        scanf("%s", comprobarsiquiere[j]);

        i++;

        if (strcmp(comprobarsiquiere[j], "No") == 0) {
            yanoquierearticulos = true;
        }
        j++;
    }

    float* arregloparaguardarlospreciosydespuesumarlos = (float*)calloc(i, sizeof(float));
    for (int j = 0; j < i; j++) {
        *(arregloparaguardarlospreciosydespuesumarlos + j) = (*(guardarprecios + arregloparaselecciondearticulo[j] - 1)) * arregloparasabercuantosquiso[j];
        printf("Precio total del artículo no. %d seleccionado: %.2f\n", j + 1, *(arregloparaguardarlospreciosydespuesumarlos + j));
    }

    printf("Ingrese con cuanto dinero va a pagar:");
    scanf("%f", &dineroconelcualpaga);
}

void imprimirTicket(int cantidaddearticulos, int* arregloparasabercuantosquiso, char** guardar_articulos, float* guardarprecios, char caracteresnovacios[][100]) {
    printf("\n-------------------------------------------------------\n");
    printf("TICKET DE VENTA\n");
    printf("-------------------------------------------------------\n");
    float subtotal = 0;
    float impuesto = 0;
    float total = 0;

    for (int i = 0; i < cantidaddearticulos; i++) {
        if (arregloparasabercuantosquiso[i] > 0) {
            printf("%s\t\t\t%.2f MXN\n", *(guardar_articulos + i), *(guardarprecios + i));
            subtotal += (*(guardarprecios + i) * arregloparasabercuantosquiso[i]);
        }
    }

    impuesto = subtotal * 0.16;
    total = subtotal + impuesto;

    printf("\n-------------------------------------------------------\n");
    printf("Subtotal:\t\t%.2f MXN\n", subtotal);
    printf("Impuesto (16%%):\t\t%.2f MXN\n", impuesto);
    printf("Total:\t\t\t%.2f MXN\n", total);
    printf("-------------------------------------------------------\n");

    // Parte para editar artículos:
    printf("\n-------------------------------------------------------\n");
    printf("EDICIÓN DE ARTÍCULOS\n");
    printf("-------------------------------------------------------\n");
    int opcion = 0;
    printf("¿Desea editar algún artículo? (Ingrese el número del artículo o 0 para salir): ");
    scanf("%d", &opcion);

    if (opcion != 0 && opcion <= cantidaddearticulos) {
        printf("Ingrese el nuevo nombre del artículo %d: ", opcion);
        scanf("%s", guardar_articulos[opcion - 1]);
        printf("Ingrese el nuevo precio del artículo %d: ", opcion);
        scanf("%f", guardarprecios + (opcion - 1));
        printf("Artículo %d actualizado.\n", opcion);

        imprimirTicket(cantidaddearticulos, arregloparasabercuantosquiso, guardar_articulos, guardarprecios, caracteresnovacios);
    }

    printf("\n¡Gracias por su compra!\n");
}
