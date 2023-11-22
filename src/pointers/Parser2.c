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
    if (c == 'Q' && nc != 'Q') {
        nc = '+';
        notp();
    } else if (c == '+' || (nc == 'Q' && c == 'Q')) {
        nc = 'Q';
        notp();
    } else if (c == '$' && nc == 'Q') {
        nc = 'Q';
    }
}

void notp() {
    if (nc == '+' || nc == 'Q') {
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

    if (c == '$' && nc == 'Q') {
        printf("Success analisis");
    } else {
        printf("Error");
    }

    return 0;
}
