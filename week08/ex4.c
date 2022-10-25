#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

// I called function my_realloc to avoid problems with name collision
void* my_realloc(void *ptr, int size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) {
        return malloc(size);
    }
    
    void *result = malloc(size);

    memcpy(result, ptr, (size > malloc_usable_size(ptr)) ? malloc_usable_size(ptr) : size);

    free(ptr);
    return result;
}

// I used example from exercise 3 to test my program
int main() {
	srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ", a1[i]);
	}
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	a1 = my_realloc(a1, n2*sizeof(int));

	for (int i = n1; i < n2; i++) {
        a1[i] = 0;
    }
	

	for(i=0; i<n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");

    free(a1);
	
	return EXIT_SUCCESS;
}