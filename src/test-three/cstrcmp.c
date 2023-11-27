#include <stdio.h>
#include <stdlib.h>

char *getline() {
    char *line = NULL;
    char inchar;
    int len = 0;

    while ((inchar = getchar()) != EOF) {
        /** Skip first char if it was a new line */
        /** Skip first char if it was a new line */
        if (inchar == '\n' && len == 0) {
            continue;
        } else if (inchar == '\n' && len > 0) {
            break;
        }

        char *temp = realloc(line, len + 2);

        if (temp == NULL) {
            printf("Error reallocating memory\n");
            free(line);
            return NULL;
        }

        line = temp;
        line[len] = inchar;
        len += 1;
    }

    if (line != NULL) {
        line[len] = '\0';
    }

    return line;
}

int cstrcmp(char *a, char *b) {
    int i = 0;

    while (a[i] == b[i]) {
        if (a[i] != '\0' && b[i] == '\0') {
            return (int)a[i];
        } else if (a[i] == '\0' && b[i] != '\0') {
            return -(int)b[i];
        } else if (a[i] == '\0' && b[i] == '\0') {
            return 0;
        }

        i++;
    }

    return a[i] - b[i];
}

int main() {
    char *stra, *strb;

    printf("Type first string: ");
    stra = getline();
    printf("Type second string: ");
    strb = getline();

    printf("Result: %d\n", cstrcmp(stra, strb));

    return 0;
}
