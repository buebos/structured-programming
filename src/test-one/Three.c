#include <stdio.h>

int main() {
    float total = 0;
    float discount = 0;
    char membershipCategory = ' ';

    printf("Type the amount of icecream you bought: ");
    scanf("%f", &total);
    printf("Type your membership category (A, B, C): ");
    scanf("%s", &membershipCategory);

    if (membershipCategory == 'A') {
        total = total * (0.9);
    } else if (membershipCategory == 'B') {
        total = total * (0.85);
    } else if (membershipCategory == 'C') {
        total = total * (0.8);
    } else {
        printf("ERROR: Invalid membership category");
        return 1;
    }

    printf("Your total is: $%0.2f", total);

    return 0;
}