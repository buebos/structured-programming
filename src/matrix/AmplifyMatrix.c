#include <stdio.h>
#include <stdlib.h>

#include "FloatMatrix.h"

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

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < p; k++) {
                for (l = 0; l < q; l++) {
                    result[k + i * p][l + j * q] = matrix1[i][j] * matrix2[k][l];
                }
            }
        }
    }

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
