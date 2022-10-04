#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int filedes[2], nbytes;
    pid_t childpid;
    char *message;
    int message_l;
    char readbuffer[2048];

    pipe(filedes);
    
    if((childpid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    if(childpid == 0) {
        close(filedes[0]);

        while (true) {
            printf("Enter message to send: ");
            getline(&message, &message_l, stdin);
            write(filedes[1], message, strlen(message)+1);
        }
        exit(EXIT_SUCCESS);
    } else {
        close(filedes[1]);

        while (true) {
            nbytes = read(filedes[0], readbuffer, sizeof(readbuffer));
            printf("Message: %s\n", readbuffer);
        }
    }
    
    return(0);
}