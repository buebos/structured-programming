#include <stdio.h>
#include <string.h>

int main() {
    char name[100] = "";
    int nameLen = 0;

    printf("Type your name: ");
    scanf("%s", &name);

    nameLen = strlen(name);

    printf("Your name in reverse: ");

    for (int i = nameLen - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }

    return 0;
}