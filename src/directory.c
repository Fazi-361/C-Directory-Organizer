#include "../include/directory.h"
#include "../include/fileUtils.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>

DIR *openDirectory(const char* directoryPath) {
    DIR *folder = opendir(directoryPath);

    if (folder == NULL) {
        printf("Impossibile aprire la directory \"%s\"", directoryPath);
    }
    return folder;
}

void closeDirectory(DIR *directory) {
    if (directory == NULL)
        return;
    closedir(directory);
}

// NOTE: directory MUST be open
void printDirectory(DIR *directory) {
    struct dirent *entry;
    while( (entry=readdir(directory)) ) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        printf("%s  -> %s\n",
            entry->d_name,
            getCategoryByExtension(strrchr(entry->d_name, '.')));
    }
}
