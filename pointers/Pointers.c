#include <stdio.h>

int main() {
    int natural = 1024;
    int *naturalRef = &natural;
    char *charRef = (char *)naturalRef;

    printf("\n --- NATURAL REFS ---\n");

    printf("naturalRef: address = %d, value = %d\n", naturalRef, *naturalRef);
    printf("naturalRef + 1: address = %d, value = %d\n", naturalRef + 1, *(naturalRef + 1));

    printf("\n --- CHAR REFS ---\n");

    printf("charRef + 0: address = %d, value = %d\n", charRef, *charRef);
    printf("charRef + 1: address = %d, value = %d\n", charRef + 1, *(charRef + 1));
    printf("charRef + 2: address = %d, value = %d\n", charRef + 2, *(charRef + 2));
    printf("charRef + 3: address = %d, value = %d\n", charRef + 3, *(charRef + 3));

    return 0;
}