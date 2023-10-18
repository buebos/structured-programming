#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char *name;
    char *author;
};

char *getline() {
    char *line = NULL;
    char inchar;
    int len = 0;

    while ((inchar = getchar()) != EOF) {
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
        line[len] = '\0';  // Null-terminate the string
    }

    return line;
}

void menu(int *section) {
    printf("[1] Add a song\n");
    printf("[2] Show the list of all songs\n");
    printf("[3] Search a song by name or author\n");
    printf("[4] Exit\n");

    printf("\n\nType the number to go to that section: ");
    scanf("%d", section);

    while ((*section) > 4 || (*section) < 1) {
        printf("\nType a valid section please: ");
        scanf("%d", section);
    }

    printf("\n\n");
}

void addSong(struct Song *songs, int *currentSongIndexPtr) {
    int songsLen = *currentSongIndexPtr;

    if (songsLen > 4) {
        printf("You can't add more songs. Song list is full!\n");
        return;
    }

    printf("Type the song name [%d]: ", songsLen + 1);
    songs[songsLen].name = getline();
    printf("Type the song author [%d]: ", songsLen + 1);
    songs[songsLen].author = getline();

    (*currentSongIndexPtr) += 1;
}

void displaySongs(struct Song *songs, int songsLen) {
    for (int i = 0; i < songsLen; i++) {
        printf("[%d] Name: %s\n", i + 1, songs[i].name);
        printf("[%d] Author: %s\n", i + 1, songs[i].author);
        printf("\n\n");
    }
}

void searchSong(struct Song *songs, int songsLen) {
    char *query;
    int found = 0;
    printf("Type the song name or author to search it: ");
    query = getline();

    printf("Songs found:\n");

    for (int i = 0; i < songsLen; i++) {
        if (strcmp(songs[i].name, query) == 0 || strcmp(songs[i].author, query) == 0) {
            printf("[%d] Author: %s\n", i + 1, songs[i].author);
            printf("[%d] Name: %s\n", i + 1, songs[i].name);
            printf("\n\n");
            found = 1;
        }
    }

    if (!found) {
        printf("A matching song was not found for query: %s\n", query);
    }
}

int main(int argc, char **argv) {
    struct Song songs[5];
    int songsLen = 0;
    int section = -1;
    int stop = 0;

    while (!stop) {
        menu(&section);

        if (section == 1) {
            addSong(songs, &songsLen);
        } else if (section == 2) {
            displaySongs(songs, songsLen);
        } else if (section == 3) {
            searchSong(songs, songsLen);
        } else {
            stop = 1;
        }
    }
    printf("\n\n ==== BYE ====");

    return 0;
}