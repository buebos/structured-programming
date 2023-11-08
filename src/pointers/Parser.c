#include <stdio.h>

void notp();

char c = '\0';
char nc = '\0';

void match(char *c1) {
    if (nc == *c1) {
        printf("Type the next character: ");
        /**
         * - Notice the space on the formatter " %c" to skip any blank characters
         * - Use the pointer not from the parameter but from the global variable
         */
        scanf(" %c", &c);
    }
}

void p() {
    if (c == 'Q') {
        nc = '+';
        notp();
    }
}

void notp() {
    if (nc == '+') {
        match(&nc);
        match(&c);
        p();
    }
}

int main(int argc, char **argv) {
    int stop = 0;

    printf("Type the character: ");
    scanf("%c", &c);

    p();

    if (c == '$') {
        printf("Success analisis");
    } else {
        printf("Error");
    }

    return 0;
}
