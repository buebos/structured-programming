#include <stdio.h>
#include <string.h>

int main() {
    char pass[5] = "1234";

    while (strcmp(pass, "UABC") != 0) {
        printf("Type the password: ");
        scanf("%s", &pass);
    }

    printf("Congrats! Pass is UABC");

    return 0;
}