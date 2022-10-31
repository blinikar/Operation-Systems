#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

struct rusage res;

int main(void) {
    void *arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = malloc(10485760);
        if (arr[i]) memset(arr[i], 0, 10485760);
        getrusage(RUSAGE_SELF, &res);

        printf("Maximum size: %ld\n", res.ru_maxrss);
        printf("N swops: %ld\n", res.ru_nswap);

        sleep(1);
    }

    for (int i = 0; i < 10; i++) free(arr[i]);
    return EXIT_SUCCESS;
}

/**
 * This experiment also confirms that all memeoru size is increasing, but
 * OS don't count that it should make a swap.
*/