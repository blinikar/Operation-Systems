#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end) {
	int result = 0;
	for (int i=start; i<end; i++){
		result += u[i] * v[i];
	}
	return result;
}

int main(void) {
    int u[120];
    int v[120];

    int ids[120];

    srand(time(NULL));

    for (int i = 0; i < 120; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    FILE* pFile;
    pFile = fopen("temp.txt", "w");
    if (pFile == NULL) return EXIT_FAILURE;

    int n;
    scanf("%d", &n);

    int l = 120 / n;
    for (int i = 0; i < n; i++) {
        int pid_t = fork();
        ids[i] = pid_t;

        if (pid_t > 0) {
            continue;
        } 
        if (pid_t == 0) {
            if (i+1 == n) fprintf(pFile, "%d\n", dotprod(u, v, i*l, 120));
            else fprintf(pFile, "%d\n", dotprod(u, v, i*l, i*l+l));
            exit(EXIT_SUCCESS);
        } else {
            printf("Fork error\n");
            return EXIT_FAILURE;
        }
    }

    fclose(pFile);
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    FILE* rFile;
    rFile = fopen("temp.txt", "r");
    int result = 0;
    if (rFile != NULL)
    {
        for (int i = 0; i < n; i++) {
            int buff;
            fscanf(rFile, "%d", &buff);
            result += buff;
        }
        fclose(rFile);
    }

    printf("%d\n", result);

	return EXIT_SUCCESS;
}