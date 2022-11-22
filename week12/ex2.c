#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int main (void) {
	DIR *dirp = opendir("/");

	struct dirent *entry;

	if (dirp == NULL) return EXIT_FAILURE;

	while ((entry = readdir(dirp)) != NULL) {
		if (entry->d_name[0] != '.') {
            		char path[256];
            		strcpy(path, "/");
    			strcat(path, entry->d_name);
			printf("%s\n", path);
        	}
	}

	return EXIT_SUCCESS;
}
