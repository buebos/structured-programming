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