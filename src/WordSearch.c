#include <stdio.h>

int arrlen(const void **arr) {
    return sizeof(arr);
}
int cstrlen(const char *arr) {
    int i = 0;

    while (arr[i] != *"\0") {
        i++;
    }

    return i;
}
int csetstrsplit(const char *str, const char *separators, char splitted[100][100]) {
    int i = 0, j = 0, k = 0;
    int separatorsLen = cstrlen(separators);

    while (str[i] != *"\0") {
        int isSeparator = 0;

        for (int l = 0; l < separatorsLen; l++) {
            if (separators[l] == str[i]) {
                isSeparator = 1;
            }
        }

        if (isSeparator) {
            splitted[j][k] = *"\0";
            j++;
            k = 0;
        } else {
            splitted[j][k] = str[i];
            k++;
        }
        i++;
    }

    if (str[0] != *"\0") {
        j++;
    }

    splitted[j][k] = *"\0";

    return j;
}
int cstrequal(const char *str1, const char *str2) {
    int strlen1 = 0;
    int strlen2 = 0;

    if (strlen1 != strlen2) {
        return 0;
    }

    for (int i = 0; i < strlen1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }

    return 1;
}

void assignString(char *toAssign[], char *assignment[]) {
    int i = 0;
    int maxStringSize = 0;

    while (toAssign[i] != "\0") {
        maxStringSize++;
        i++;
        printf("%d", i);
    }
    i = 0;
    while (assignment[i] != "\0") {
        if (i > maxStringSize) {
            maxStringSize++;
        }
        i++;
    }

    printf("%s", maxStringSize);

    for (i = 0; i < maxStringSize; i++) {
        toAssign[i] = assignment[i];
    }

    return;
}

void fillStringArray(char *stringArr[][100], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        stringArr[i][0] = "\0";
    }

    return;
}

int main(int argc, char *argv[]) {
    const char TEXT[] = "Hello world\nfrom x";
    const char SEPARATORS[] = " \n\t";
    char searchWords[100][100];
    char foundWords[100][100];
    char textWords[100][100];
    int wordsLen = csetstrsplit(TEXT, SEPARATORS, textWords);
    int searchWordsLen = 5;

    for (int i = 0; i < searchWordsLen; i++) {
        for (int j = 0; j < wordsLen; j++) {
            if (cstrequal(searchWords[i], textWords[j])) {
                
            }
        }
    }

    return 0;
}
