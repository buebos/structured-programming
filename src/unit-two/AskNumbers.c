#include <stdio.h>

int main() {
    int naturals[10];

    for (int i = 0; i < 10; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &naturals[i]);
    }

    printf("[");
    for (int i = 9; i >= 0; i--) {
        printf("%d", naturals[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}