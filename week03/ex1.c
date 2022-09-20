#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(int age){	
	return 2022 - age;
}

int main(){
    const int x = 10;
    const int const *q = &x;

    int* const p = (int*) malloc(sizeof(int)*5);
    
    for (int i = 0; i < 5; i++) {
        *(p + i) = x;
        printf("%p\n", p + i);
    }

    for (int i = 0; i < 5; i++) {
        scanf("%d", p + i);
        *(p + 1) = foo(*(p + 1));
    } 

    free(p);
	return EXIT_SUCCESS;
}