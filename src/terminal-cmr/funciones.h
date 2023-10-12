#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

void agregarArticulos(int cantidaddearticulos, int* guardarcaracteresnovacios, float* guardarprecios, char** guardararticulos, char caracteresnovacios[][100]);
void imprimirArticulos(int cantidaddearticulos, int* guardarcaracteresnovacios, char** guardararticulos, float* guardarprecios);
void contarArticulos(int cantidaddearticulos, int* arregloparasabercuantosquiso, char comprobarsiquiere[5][100], float* guardarprecios);
void imprimirTicket(int cantidaddearticulos, int* arregloparasabercuantosquiso, char** guardararticulos, float* guardarprecios, char caracteresnovacios[][100]);

#endif