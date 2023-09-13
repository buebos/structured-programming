#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *concat(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) return "\0";

    char *result = malloc(strlen(s1) + strlen(s2) + 1);  // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int searchForExe(char *basePath, char *filename, char *args, int depth) {
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

            if (strcmp(dp->d_name, filename) == 0) {
                char *command = concat(path, concat(" ", args));
                int status = system(command);

                free(command);

                return status;
            } else if (S_ISDIR(statbuf.st_mode)) {
                searchForExe(path, filename, args, depth + 1);
            }
        }
    }

    closedir(dir);

    return -1;
}

int main(int argc, char *argv[]) {
    char path[100] = "dist";
    char *executable = argv[1];
    char *filename = concat(executable, ".exe");
    char *argv2;
    int k = 0;
    int totalLen = 0;

    for (int i = 0; i < argc - 2; i++) {
        totalLen += strlen(argv[i + 2]) + 1;
    }
    argv2 = malloc((totalLen + 1) * sizeof(char));
    if (argv2 == NULL) {
        printf("[RUN-ERROR]: Failed to allocate memory for argv2\n");
        return 1;
    }
    for (int i = 0; i < argc - 2; i++) {
        int argLen = strlen(argv[i + 2]);
        for (int j = 0; j < argLen; j++) {
            argv2[k] = argv[i + 2][j];
            k++;
        }
        argv2[k] = *" ";
        k++;
    }
    argv2[k] = '\0';

    if (argc < 2) {
        printf("[RUN-ERROR]: Please provide the name of the executable\n");
        return 1;
    }

    int status = searchForExe(path, filename, argv2, 0);

    for (int i = 0; i < argc - 2; i++) {
        free(argv2);
    }
    free(argv2);

    if (status == -1) {
        printf("\n[RUN-ERROR]: Executable %s not found on dist folder\n", filename);
        return 1;
    }

    if (status != 0) {
        printf("\n[RUN-ERROR]: Your executable from dist folder returned with error code %d\n", status);
        return status;
    }

    return 0;
}
