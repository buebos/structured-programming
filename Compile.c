#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void printe(char *msg) {
    printf("[ERROR]: %s\n", msg);
}

int get_invalid_dirs_len() {
    return 2;
}

void arrange_file_compiling_name(char *file_compiling, char *arg_name) {
    file_compiling = malloc(sizeof(arg_name));

    strcpy(file_compiling, arg_name);

    int len = strlen(file_compiling);

    if (file_compiling[len - 2] == *"." && file_compiling[len - 1] == *"c") {
        printf("%s", file_compiling);
        return;
    }

    file_compiling = realloc(file_compiling, len + 2);

    strcat(file_compiling, ".c");

    printf("%s", file_compiling);
}

char **get_invalid_dirs() {
    const int invalid_dirs_len = get_invalid_dirs_len();
    char **invalid_dirs = malloc(sizeof(char *) * invalid_dirs_len);

    for (int i = 0; i < invalid_dirs_len; i++) {
        invalid_dirs[i] = malloc(sizeof(char) * 10);

        if (i == 0) {
            strcpy(invalid_dirs[i], "dist");
        } else {
            strcpy(invalid_dirs[i], "build");
        }
    }

    return invalid_dirs;
}

bool is_valid_dir(char *dir_name) {
    if (dir_name[0] == *".") {
        return false;
    }
    char **invalid_dirs = get_invalid_dirs();

    for (int i = 0; i < get_invalid_dirs_len(); i++) {
        if (strcmp(dir_name, invalid_dirs[i]) == 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printe("Please provide the name of the C file to compile");
        return 1;
    }

    char *file_compiling;
    char *dir_path = malloc(sizeof(char) * 10);

    arrange_file_compiling_name(file_compiling, argv[1]);
    strcpy(dir_path, ".");

    DIR *current_dir = opendir(dir_path);
    char *root_dir_path = malloc(strlen(current_dir->dd_name));
    struct dirent *dp = readdir(current_dir);
    struct stat path_stat;

    strcpy(root_dir_path, current_dir->dd_name);

    if (!current_dir) {
        printe("Could not open current dir");
        return 1;
    }

    while (dp != NULL) {
        stat(dp->d_name, &path_stat);

        if (strcmp(dp->d_name, file_compiling) == 0) {
            printf("File compiling found: %s\n", dp->d_name);
        } else if (S_ISDIR(path_stat.st_mode) && is_valid_dir(dp->d_name)) {
            current_dir = opendir(dp->d_name);
            printf("Going into dir: %s\n", dp->d_name);
        }

        dp = readdir(current_dir);

        if (dp == NULL && strcmp(current_dir->dd_name, root_dir_path) != 0) {
            current_dir = opendir("..");
        }
    }

    closedir(current_dir);
    free(dir_path);

    return 0;
}