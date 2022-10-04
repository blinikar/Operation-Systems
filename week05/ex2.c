#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

struct Thread {
    int i;
    pthread_t* id;
    char message[256];
};
typedef struct Thread Thread;

void *myThreadFun(Thread *thread) {
    printf("ID:%ld Message: %s\n", (long) *thread->id, thread->message);
    return NULL;
}
  
int main() {
    int n;
    scanf("%d", &n);

    Thread* threads[256];

    for (int i = 0; i < n; i++) {
        Thread* thread = malloc(sizeof(Thread));
        thread->i = i;
        sprintf(thread->message, "Hello from thread %d", i);
        pthread_t* thread_id = malloc(sizeof(pthread_t));
        thread->id = thread_id;
        pthread_create(thread_id, NULL, myThreadFun, thread);
        printf("Thread %d is created\n", i);
        threads[i] = thread;
        pthread_join(*thread_id, NULL);
        free(thread_id);
    }

    for (int i = 0; i < n; i++) {
        free(threads[i]);
    }

    return EXIT_SUCCESS;
}