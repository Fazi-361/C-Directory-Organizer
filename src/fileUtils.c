//
// Created by tayx3 on 14/08/2026.
//
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "../include/fileUtils.h"

FileType extensions[] = {
    {".jpg", "Image"},
    {".png", "Image"},
    {".jpeg", "Image"},
    {".gif", "Image"},
    {".svg", "Image"},
        // Document
    {".pdf", "Document"},
    {".txt", "Document"},
    {".docx", "Document"},
        // Audio
    {".mp3", "Audio"},
    {".wav", "Audio"},
        // Video
    {".mp4", "Video"},
    {".mkv", "Video"}
};


char *getCategoryByExtension(const char *extension) {
    if (extension == NULL)
        return "None";

    for (int i=0; i < sizeof(extensions) / sizeof(extensions[0]); ++i) {
        if (strcmp(extensions[i].extension, extension) == 0) {
            return extensions[i].category;
        }
    }
    return "Other";
}

char *getCategoryByFile(struct dirent file) {
    //return getCategoryByExtension(strrchr(file->d_name, '.'));
    return "";
}
