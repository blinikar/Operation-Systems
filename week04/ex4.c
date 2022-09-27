#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

int main(void) {
    char* command;
    int command_l;

    while(true) {
        getline(&command, &command_l, stdin);
        int pid = fork();
        if (pid == 0) {
            system(command);
            exit(EXIT_SUCCESS);
        }
    }

	return EXIT_SUCCESS;
}

// Example on using system
// https://www.codingunit.com/c-reference-stdlib-h-function-system

// Example on using execve
// https://linuxhint.com/c-execve-function-usage/