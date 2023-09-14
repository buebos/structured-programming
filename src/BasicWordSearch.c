#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("[ERROR]: Please provide the text and words to search as arguments");
        return 1;
    }

    const char *TEXT = argv[1];
    int textLength = 0;

    while (TEXT[textLength] != *"\0") {
        textLength++;
    }

    for (int i = 2; i < sizeof(*argv); i++) {
        const char *searchWord = argv[i];
        int searchWordLength = 0;
        int k = 0;
        int isEqualWord = 1;
        int timesFound = 0;

        while (searchWord[searchWordLength] != *"\0") {
            searchWordLength++;
        }

        for (int j = 0; j < textLength; j++) {
            if (TEXT[j] == *" " || TEXT[j] == *"\n" || TEXT[j] == *"\t" || TEXT[j] == *"," || TEXT[j] == *"." || TEXT[j] == *";" || TEXT[j] == *":") {
                if (isEqualWord && k == searchWordLength) {
                    timesFound++;
                }

                k = 0;
                isEqualWord = 1;
            } else if (TEXT[j] != searchWord[k]) {
                k = 0;
                isEqualWord = 0;
            } else if ((isEqualWord && TEXT[j] == searchWord[k])) {
                k++;
            }

            if (j == textLength - 1 && k == searchWordLength && isEqualWord) {
                timesFound++;
            }
        }

        printf("[INFO]: Found '%s' %d times\n", searchWord, timesFound);
    }

    return 0;
}