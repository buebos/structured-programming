#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int floors = 0, base = 0;
    if (argc < 2) {
        printf("[INFO] Please specify the number of floors of the triangle: ");
        scanf("%d", &floors);
        printf("\n");
    } else {
        floors = atoi(argv[1]);
    }
    base = floors * 2 - 1;

    for (int i = 1; i <= floors; i++) {
        int starCount = i * 2 - 1;
        int spaceCount = (base - starCount) / 2;

        for (int j = 1; j <= base; j++) {
            if (j <= spaceCount || j > (spaceCount + starCount)) {
                printf(" ");
            } else {
                printf("*");
            }
        }

        printf("\n");
    }

    return 0;
}