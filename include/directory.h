//
// Created by tayx3 on 14/08/2026.
//

#ifndef ORGANIZER_DIRECTORY_H
#define ORGANIZER_DIRECTORY_H
#include <dirent.h>

DIR *openDirectory(const char* directoryPath);
void closeDirectory(DIR *directory);
void printDirectory(DIR *directory);

#endif //ORGANIZER_DIRECTORY_H
