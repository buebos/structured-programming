#include <stdio.h>
#include <stdlib.h>

void cstrcat(char* str1, char* str2) {
    int len1 = 0;
    int len2 = 0;
    int i = 0;

    while (str1[len1] != '\0') {
        len1 += 1;
    }

    while (str2[len2] != '\0') {
        len2 += 1;
    }

    for (i = len1; i < len1 + len2; i++) {
        str1[i] = str2[i - len1];
    }

    str1[i + 1] = '\0';
}

int main() {
    char* str1 = calloc(15, sizeof(char));
    char* str2 = calloc(10, sizeof(char));

    cstrcat(str1, "hola");
    printf("String 1: %s\n", str1);

    cstrcat(str2, "world");
    printf("String 2: %s\n", str2);

    cstrcat(str1, str2);

    printf("Result: %s\n", str1);

    return 0;
}