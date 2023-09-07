#include <stdio.h>
#include <string.h>

int main() {
    const char CORRECT_PASSWORD[] = "1234";
    const int MAX_TRIES = 3;
    char password[5];
    int tries = 0;
    int isCorrect = 0;

    float numToSum;
    float sum = 0;

    int gradeAmount = 0;
    float gradeCurrent;
    float gradeHolder = 0;

    while (tries < 3 && !isCorrect) {
        printf("Type the password: ");
        scanf("%s", password);

        isCorrect = strcmp(password, CORRECT_PASSWORD) == 0;

        if (!isCorrect) {
            tries += 1;
            printf("ERROR: Wrong password. Tries left: %d.\n", MAX_TRIES - tries);
        } else {
            printf("Correct password! Welcome to the program\n");
        }

        if (tries == MAX_TRIES) {
            printf("ERROR: Sorry you have run out of tries, try again later\n");
        }
    }

    do {
        printf("Type the number below zero to sum (if the number is greater the sum will not be done): ");
        scanf("%f", &numToSum);

        if (numToSum < 0) {
            sum += numToSum;
        }
    } while (numToSum < 0);

    printf("The sum of all negative numbers you typed is: %0.2f\n", sum);

    printf("Type the amount of grades you wish to input: ");
    scanf("%d", &gradeAmount);

    for (int i = 1; i <= gradeAmount; i++) {
        printf("Type the grade number %d: ", i);
        scanf("%f", &gradeCurrent);

        while (gradeCurrent < 0 || gradeCurrent > 10) {
            printf("ERROR: Please be sure to type grades between 0 and 10 (including). Type it again: ");
            scanf("%f", &gradeCurrent);
        }

        gradeHolder += gradeCurrent;
    }

    gradeHolder = gradeHolder / gradeAmount;

    printf("The average is: %f\n", gradeHolder);

    if (gradeHolder < 6) {
        printf("You did not passed\n");
    } else {
        printf("You passed!\n");
    }

    return 0;
}