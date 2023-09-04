#include <stdio.h>

int main() {
    const float SHOES_PRICE = 80;
    float discount = 0;
    int shoesAmount = 0;
    float total = 0;

    printf("How many shoes do you want to buy? ");
    scanf("%d", &shoesAmount);

    if (shoesAmount > 30) {
        discount = 0.4;
    } else if (shoesAmount > 20) {
        discount = 0.2;
    } else if (shoesAmount > 10) {
        discount = 0.1;
    }

    total = shoesAmount * SHOES_PRICE * (1 - discount);

    printf("Your grand total is: $%0.2f", total);

    return 0;
}