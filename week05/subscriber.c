#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd1;

    char * myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);

    char str[2048];
    fd1 = open(myfifo,O_RDONLY);
    while (true) {
        read(fd1, str, 2048);
        printf("Message: %s\n", str);
    }
    close(fd1);
    return 0;
}