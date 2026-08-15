#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "../include/directory.h"
#include "../include/fileUtils.h"
#include "../include/systemOperations.h"

int main(int argc, char* argv[]){
    char pathName[200];
    if (argc > 1) {
        strcpy(pathName, argv[1]);
    }
    else {
        printf("Inserire la directory da organizzare:\t");
        fgets(pathName, sizeof(pathName), stdin);
        pathName[strcspn(pathName, "\n")] = '\0';
    }
    printf("%s\n", pathName);

    DIR *directory = openDirectory(pathName);
    if (directory == NULL) {
        printf("Impossibile aprire la cartella.");
        return 1;
    }
    printf("Directory aperta.\n");
    //printDirectory(directory);

    organize(directory, pathName);

    closeDirectory(directory);
    return 0;
}
