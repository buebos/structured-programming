#include <stdio.h>
#include <string.h>

int main() {
    char names[5][100];
    char nameSearch[100];
    int stop = 0;
    int i = 0, isExistingName = 0;

    for (i = 0; i < 5; i++) {
        printf("Type name number %d: ", i);
        scanf("%s", names[i]);

        if (strcmp(names[i], "fin") == 0) {
            printf("Bye!");
            return 0;
        }
    }

    while (!stop) {
        printf("Type a name to search: ");
        scanf("%s", nameSearch);

        if (strcmp(nameSearch, "fin") == 0) {
            printf("Bye!");
            return 0;
        }

        i = 0;
        isExistingName = 0;

        for (i = 0; i < 5; i++) {
            if (strcmp(nameSearch, names[i]) == 0) {
                isExistingName = 1;
                break;
            }
        }

        if (!isExistingName) {
            printf("Name not found\n");
        } else {
            printf("Name exists\n");
        }
    }

    return 0;
}