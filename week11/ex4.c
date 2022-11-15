#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    DIR *dirp = opendir("tmp");
    struct dirent *entry;
    struct stat info;

    if (dirp == NULL) { 
        return EXIT_FAILURE; 
    }

    FILE* file = fopen("ex4.txt", "w");

    char* names[256];
    int inodes[256];
    int counter = 0;

    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_name[0] != '.') {
            char path[256];
            strcpy(path, "tmp/");
            strcat(path, entry->d_name);
            if (stat(path, &info) != 0) {
                closedir(dirp);
                return EXIT_FAILURE;
            } else {
                names[counter] = entry->d_name;
                inodes[counter] = info.st_ino;
                counter++;
            }
        }
    }
    closedir(dirp);

    char* links[256];
    for (int i = 0; i < counter; i++) {
        int count = 0;

        for (int j = 0; j < counter; j++) {
            if (inodes[i] == inodes[j]) {
                links[count] = names[j];
                count++;
            }
        }

        if (count >= 2) {
            fprintf(file, "%s - ", names[i]);
            for (int j = 0; j < count; j++) {
                if (j == 0) fprintf(file, "%s", links[j]);
                else fprintf(file, ", %s", links[j]);
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}