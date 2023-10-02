#include <stdio.h>
#include <string.h>

int main() {
    char text[51] = "";
    char second[51] = "";
    char copy[51] = "";

    printf("Type a word: %s", text);
    scanf("%s", &text);

    printf("Type a word concat it with text: %s", second);
    scanf("%s", &second);

    strcat(text, second);
    strcpy(copy, text);

    printf("Copy value: %s\n", copy);

    return 0;
}