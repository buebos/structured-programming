#include <stdio.h>
#include <string.h>

int power(int x, int y, int acum, int i) {
    if (i > y) {
        return acum;
    }

    return power(x, y, acum * x, i + 1);
}

int main() {
    int x = 0, y = 0;

    printf("Type the base: ");
    scanf("%d", &x);

    printf("Type the power: ");
    scanf("%d", &y);

    printf("Result: %d", power(x, y, 1, 1));

    return 0;
}