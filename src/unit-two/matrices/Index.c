#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char names[100][100];
    int i = 0, j = 0, isExistingName = 0;

    for (i = 0; i < 100; i++) {
        printf("Type name number %d: ", i);
        scanf("%s", names[i]);

        if (strcmp(names[i], "fin") == 0) {
            j = i;
            break;
        }

        while (isExistingName) {
            for (j = 0; j < i; j++) {
                isExistingName = strcmp(names[i], names[j]) == 0;

                if (isExistingName) {
                    printf("Name already exists on index %d, type other: ", j);
                    scanf("%s", names[i]);
                }
            }
        }

        j = 100;
    }

    printf("\n=== NAMES ===\n");

    for (i = 0; i < j; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}