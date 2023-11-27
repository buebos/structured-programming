#include <stdio.h>
#include <stdlib.h>

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

    if (matrix == NULL) {
        printf("[ERROR]: Could not allocate matrix on FloatMatrix function, this will probablly throw a segmentation fault!");
    }

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

int main() {
    int n = 0, m = 0, p = 0, q = 0;

    printf("Type the rows for matrix a: ");
    scanf("%d", &n);
    printf("Type the columns for matrix a: ");
    scanf("%d", &m);
    float **matrixa = FloatMatrix(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Type the cell [%d][%d] for matrix a: ", i, j);
            scanf("%f", &matrixa[i][j]);
        }
    }

    printf("Type the rows for matrix b: ");
    scanf("%d", &p);
    printf("Type the columns for matrix b: ");
    scanf("%d", &q);
    float **matrixb = FloatMatrix(p, q);

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("Type the cell [%d][%d] for matrix b: ", i, j);
            scanf("%f", &matrixb[i][j]);
        }
    }

    if (m != p) {
        printf("[ERROR]: The matrix dimensions are wrong!\n");
        return 1;
    }

    float **matrixres = FloatMatrix(q, n);

    for (int a = 0; a < q; a++) {
        for (int i = 0; i < n; i++) {
            int suma = 0;
            for (int j = 0; j < m; j++) {
                suma += matrixa[i][j] * matrixb[j][a];
            }
            matrixres[i][a] = suma;
        }
    }

    printf("\n=== RESULT ===\n");
    printFloatMatrix(matrixres, q, n);

    return 0;
}
