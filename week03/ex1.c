#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(int age){	
	return 2022 - age;
}

int main(){
    const int x = 10;
    const int const *q = &x;

    const int* const p = malloc(sizeof(int)*5);
    memset(p, 10, sizeof(int)*5);

    scanf("%d", &p);
    scanf("%d", &p + sizeof(int));
    scanf("%d", &p + 2 * sizeof(int));
    scanf("%d", &p + 3 * sizeof(int));
    scanf("%d", &p + 4 * sizeof(int));

    for (int i = 0; i < 1; i++) {
        const int const age = *(&p + i * sizeof(int));
        int year = foo(age);
        const int const *pointer = &p + i * sizeof(int);
        pointer = &year; 
    }

    free(p);

	return EXIT_SUCCESS;
}