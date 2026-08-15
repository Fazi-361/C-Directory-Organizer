//
// Created by tayx3 on 14/08/2026.
//

#ifndef ORGANIZER_SYSTEMOPERATIONS_H
#define ORGANIZER_SYSTEMOPERATIONS_H
#include <dirent.h>

int makeDirectory(char* path);
void organize(DIR *directory, char *path);
char *getCorrectedPath(char *path);

#endif //ORGANIZER_SYSTEMOPERATIONS_H
