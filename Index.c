#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);  // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int searchForExe(char *basePath, char *executable, char *args, int depth) {
    const char SEPARATOR[] = "\\";
    char path[1000];
    char executables[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir) {
        return 1;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && dp->d_name[0] != *".") {
            strcpy(path, basePath);
            strcat(path, SEPARATOR);
            strcat(path, dp->d_name);

            struct stat statbuf;
            stat(path, &statbuf);

            if (strcmp(dp->d_name, executable) == 0) {
                int status = system(concat(path, concat(" ", args)));

                return status;
            } else if (S_ISDIR(statbuf.st_mode)) {
                searchForExe(path, executable, args, depth + 1);
            }
        }
    }

    closedir(dir);

    return -1;
}

int main(int argc, char *argv[]) {
    char path[100] = "dist";
    char *executable = argv[1];
    char *argv2;
    int k = 0;
    int totalLen = 0;

    for (int i = 0; i < argc - 2; i++) {
        totalLen += strlen(argv[i + 2]);
    }
    argv2 = malloc((totalLen + 1) * sizeof(char));
    if (argv2 == NULL) {
        printf("[ERROR]: Failed to allocate memory for argv2\n");
        return 1;
    }
    for (int i = 0; i < argc - 2; i++) {
        int argLen = strlen(argv[i + 2]);
        for (int j = 0; j < argLen; j++) {
            argv2[k] = argv[i + 2][j];
            printf("argv[i + 2][j] = %c\n", argv[i + 2][j]);
            printf("argv2 = %s\n", argv2);
            k++;
        }
    }
    argv2[k] = '\0';

    if (argc < 2) {
        printf("[ERROR]: Please provide the name of the executable\n");
        return 1;
    }

    int status = searchForExe(path, executable, argv2, 0);

    for (int i = 0; i < argc - 2; i++) {
        free(argv2);
    }
    free(argv2);

    if (status == -1) {
        printf("\n[ERROR]: Executable not found on dist folder\n");
        return 1;
    }

    if (status != 0) {
        printf("\n[ERROR]: Your executable from dist folder returned with error code %d\n", status);
        return status;
    }

    return 0;
}
