//
// Created by tayx3 on 14/08/2026.
//

#include "../include/systemOperations.h"
#include "../include/fileUtils.h"

#include <stdio.h>
#include <direct.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

char *getCorrectedPath(char *path) {
    char *newDirectoryPath = "";
    newDirectoryPath = strcpy(newDirectoryPath, path);

    char lastPathCharacter = path[sizeof(path) / sizeof(path[0] - 1)];
    if (lastPathCharacter == '\\') {
        newDirectoryPath = strcat(path, "\\");
    }

    return newDirectoryPath;
}

// TODO Gestisci gli errori
int makeDirectory(char* path) {
    if (_mkdir(path) == 0) {
        return 1;
    }
    if (errno == EEXIST) {
        return 0;
    }
    return -1;
}

void organize(DIR *directory, char *path) {
    struct dirent *entry;

    while ((entry = readdir(directory)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        char *entryName = entry->d_name;
        char *entryExtension = strrchr(entryName, '.');
        char *entryCategory = getCategoryByExtension(entryExtension);

        char newDirectory[300];
        char pathToEntry[300];

        // Initialize newDirectory
        snprintf(
            newDirectory,
            sizeof(newDirectory),
            "%s\\%s",
            path,
            entryCategory
        );

        // Initialize pathToEntry
        snprintf(
            pathToEntry,
            sizeof(pathToEntry),
            "%s\\%s",
            path,
            entryName
        );

        //printf("Originale: %s\n", pathToEntry);

        if (strcmp(entryCategory, "None") != 0) {

            int result = makeDirectory(newDirectory);

            if (result == 1 || result == 0) {

                char newPathToEntry[300];

                snprintf(
                    newPathToEntry,
                    sizeof(newPathToEntry),
                    "%s\\%s",
                    newDirectory,
                    entryName
                );

                //printf("Destinazione: %s\n", newPathToEntry);

                rename(pathToEntry, newPathToEntry);
            }
        }
    }
}

