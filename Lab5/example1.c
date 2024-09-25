#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void* arg) {
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", thread_id);
    sleep(1);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, thread_func, NULL) != 0) {
        printf("Error creating thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, thread_func, NULL) != 0) {
        printf("Error creating thread 2\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished execution.\n");

    return 0;
}
