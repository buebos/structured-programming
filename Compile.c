#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    struct dirent *dp;
    DIR *dir = opendir(".");

    if (!dir) {
        return 1;
    }

    while ((dp = readdir(dir)) != NULL) {
        
    }

    return 0;
}