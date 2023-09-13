#include <stdio.h>

int arrlen(const void **arr) {
    return sizeof(arr) / sizeof(arr[0]);
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
    int strlen1 = cstrlen(str1);
    int strlen2 = cstrlen(str2);

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
void cstrarrpush(char strarr[][100], char *str, int *strarrlen) {
    int i = 0;
    for (i = 0; i < cstrlen(str); i++) {
        strarr[*strarrlen][i] = str[i];
    }
    (*strarrlen)++;

    return;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("[ERROR]: Please provide the text and at least one search word as arguments.\n");
        return 1;
    }

    const char *TEXT = argv[1];
    const char WORD_SEPARATORS[] = " \n\t.,;:";
    char searchWords[100][100];
    char foundWords[100][100];
    char textWords[100][100];
    int wordsLen = csetstrsplit(TEXT, WORD_SEPARATORS, textWords);
    int searchWordsLen = 0;
    int foundWordsLen = 0;

    for (int i = 2; i < argc; i++) {
        cstrarrpush(searchWords, argv[i], &searchWordsLen);
    }

    for (int i = 0; i < searchWordsLen; i++) {
        for (int j = 0; j < wordsLen; j++) {
            if (cstrequal(searchWords[i], textWords[j])) {
                cstrarrpush(foundWords, searchWords[i], &foundWordsLen);
            }
        }
    }

    if (foundWordsLen == 0) {
        printf("[INFO]: No matches found in text, be sure to use quotes for the text to make the search on\n[EXAMPLE]: WordSearch \"Search text here\" this are words that will be searched individually");
    } else {
        for (int i = 0; i < foundWordsLen; i++) {
            printf("[INFO]: Found %d: %s\n", i + 1, foundWords[i]);
        }
    }

    return 0;
}
