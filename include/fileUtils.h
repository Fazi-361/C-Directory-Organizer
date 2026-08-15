#ifndef ORGANIZER_FILEUTILS_H
#define ORGANIZER_FILEUTILS_H

typedef struct {
    char *extension;
    char *category;
}FileType;

char *getCategoryByExtension(const char *extension);
char *getCategoryByFile(struct dirent file);
#endif //ORGANIZER_FILEUTILS_H
