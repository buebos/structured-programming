#include <stdio.h>
#include <string.h>

int main() {
    int n = 0, temp = 0;
    int numbers[100];

    printf("Type the amount of numbers to order: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        numbers[i] = -1;

        while (numbers[i] < 0) {
            printf("Type the number in position %d: ", i + 1);
            scanf("%d", &numbers[i]);
        }
    }

    printf("Ordered numbers: [");

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }

        printf("%d", numbers[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]");

    return 0;
}