#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int *arr = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        arr[i] = i; 
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);

    return EXIT_SUCCESS;
}