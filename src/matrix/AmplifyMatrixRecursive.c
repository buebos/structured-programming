#include <stdio.h>
#include <stdlib.h>

#include "FloatMatrix.h"

void multiply(float **matrix1, float **matrix2, float **result, int n, int m, int p, int q, int i, int j, int k, int l) {
    result[k + i * p][l + j * q] = matrix1[i][j] * matrix2[k][l];

    if (++l >= q) {
        l = 0;
        if (++k >= p) {
            k = 0;
            if (++j >= m) {
                j = 0;
                ++i;
            }
        }
    }

    if (i < n) {
        multiply(matrix1, matrix2, result, n, m, p, q, i, j, k, l);
    }
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("[ERROR] Please type 4 values as the arguments which will correspond to n, m, p, q for the matrixes respectivelly.\n");
        printf("[INFO] Optionally provide a max number to assign to the elements of the matrix as a 5th argument.\n");
        return 1;
    }

    /** Counters for iterations */
    int i, j, k, l;
    /** Max random number */
    int max = argc >= 6 ? atoi(argv[5]) : 10;
    /** Dimensions */
    int n = atoi(argv[1]), m = atoi(argv[2]), p = atoi(argv[3]), q = atoi(argv[4]);
    /** Matrices */
    float **matrix1 = FloatMatrixRandom(n, m, max);
    float **matrix2 = FloatMatrixRandom(p, q, max);
    float **result = FloatMatrix(n * p, m * q);

    printf("=== Matrix 1 ===\n");
    printFloatMatrix(matrix1, n, m);
    printf("=== Matrix 2 ===\n");
    printFloatMatrix(matrix2, p, q);

    multiply(matrix1, matrix2, result, n, m, p, q, i, j, k, l);

    printf("=== Result ===\n");
    printFloatMatrix(result, n * p, m * q);

    /**
     * Can be set free like this since each matrix is actually in 1D
     */
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
