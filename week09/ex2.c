#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    void *arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = malloc(10485760);
        if (arr[i]) memset(arr[i], 0, 10485760);
        sleep(1);
    }

    for (int i = 0; i < 10; i++) free(arr[i]);
    return EXIT_SUCCESS;
}

/*
    In my case there is no swap in or swap out because there is enough 
    memory to store all programs. If there is had to be less space in memory,
    Operating System would have swap data of our program shile it is sleeping. 
*/

/*
    Experiment with top command approves my hypotesis that system is not swapping 
    memmory of m program on the disk
*/