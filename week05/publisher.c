#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char * myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);

    printf("This is publisher\n");

    char arr[2048];
    fd = open(myfifo, O_WRONLY);
    while (true)
    {
        fgets(arr, 2048, stdin);
        write(fd, arr, strlen(arr)+1);
    }
    close(fd);
    return 0;
}