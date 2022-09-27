#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(void) {
    double initTime = clock();

    pid_t child_a, child_b;

    child_a = fork();

    char* subject = "Parent";
    if (child_a == 0) {
        initTime = clock();
        subject = "First child";
        printf("Hello from first child. My PID is: %d, and my Parent PID is %d\n", getpid(), getppid());
    } else {
        child_b = fork();

        if (child_b == 0) {
            initTime = clock();
            subject = "Second child";
            printf("Hello from second child. My PID is: %d, and my Parent PID is %d\n", getpid(), getppid());
        } else {
            printf("Hello from parent. My PID is: %d\n", getpid());
        }
    }

    printf("%s execution time is: %lf\n", subject, clock() - initTime);
	return EXIT_SUCCESS;
}