#ifndef _FLOAT_MATRIX_H_
#define _FLOAT_MATRIX_H_

float** FloatMatrix(int rows, int columns);
float** FloatMatrixRandom(int rows, int columns, int max);
void printFloatMatrix(float** matrix, int rows, int columns);

#endif