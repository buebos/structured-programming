#include <stdio.h>
#include <string.h>

int main() {
    char isPlaying[2] = "y";
    int continuousOnes = 0;
    int bit;

    while (strcmp(isPlaying, "y") == 0) {
        printf("[READ]: Input a bit string: ");
        scanf("%d", &bit);

        if (bit == 0) {
            continuousOnes = 0;
        } else {
            continuousOnes += 1;
        }

        if (continuousOnes >= 3) {
            printf("[INFO]: Green light!\n");
        } else {
            printf("[INFO]: Red light!\n");
        }

        printf("[READ]: Do you want to continue playing? (y/n): ");
        scanf("%s", &isPlaying);
    }

    printf("[INFO]: Goodbye!\n");
}