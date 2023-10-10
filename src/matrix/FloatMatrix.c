/** This libraries already contain declaration guards*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Returns a matrix of floats */
float **FloatMatrix(int rows, int columns) {
    /**
     * Size of the pointers for each virtual row + size of the elements in
     * the whole matrix.
     *
     * Matrix will have this form:
     *
     * ptrRow1 =+1=> ptrRow2 =+1=> ... =+1=> ptrRowN =+1=> row1 ...
     * row1 (contains floats of row one until columns - 1) =+columns=> row2 =+columns=> ... =+columns=> rowN
     */
    float **matrix = (float **)malloc(sizeof(float *) * rows + sizeof(float) * columns * rows);
    /** Skip the first virtual row as it will be the pointers location */
    float *firstElementPtr = (float *)(matrix + rows);

    /**
     * Define the pointers to each of the wirtual rows
     */
    for (int i = 0; i < rows; i++) {
        matrix[i] = (firstElementPtr + columns * i);
    }

    return matrix;
}
/** Returns a matrix of floats initialized with random numbers */
float **FloatMatrixRandom(int rows, int columns, int max) {
    float **matrix = FloatMatrix(rows, columns);
    int i, j = 0;

    /** Initialization for random numbers */
    srand(time(NULL));

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            matrix[i][j] = rand() % max + 1;
        }
    }

    return matrix;
}

void printFloatMatrix(float **matrix, int rows, int columns) {
    int i = 0, j = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%.1f\t ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
