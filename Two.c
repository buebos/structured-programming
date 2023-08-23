#include <ctype.h>
#include <stdio.h>

int main() {
    float userNumber;
    int professorCategory;
    float professorSalary;
    char a;
    int isVowel;

    printf("\n\n --- Program 1 --- \n\n");

    printf("Type a number: ");
    scanf("%f", &userNumber);

    if (userNumber > 0) {
        printf("Your number as you typed it: %f\n", userNumber);
    } else {
        userNumber = userNumber * -1;
        printf("Your number with opposite sign: %f\n", userNumber);
    }

    printf("\n\n --- Program 2 --- \n\n");

    printf("Type your professor category: ");
    scanf("%d", &professorCategory);

    printf("Type your professor salary: ");
    scanf("%f", &professorSalary);

    if (professorCategory == 1) {
        professorSalary = professorSalary * 1.15;
    } else if (professorSalary == 2) {
        professorSalary = professorSalary * 1.2;
    } else {
        printf(
            "Ups! There was an error: The professor category that you typed "
            "does not exists, please try again\n");
    }

    printf(
        "Your new salary based on the category you typed (even if the category "
        "does not exists) is: %f\n",
        professorSalary);

    printf("\n\n --- Program 3 --- \n\n");

    printf("Type a single character: ");
    scanf("%s", &a);

    if (isalpha(a)) {
        a = tolower(a);

        isVowel = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');

        if (isVowel) {
            printf("The character you typed (%c) is a vowel", a);
        } else {
            printf("The character you typed (%c) is a consonant", a);
        }

    } else if (isdigit(a)) {
        printf("The character you typed (%c) is a digit", a);
    }

    return 0;
}