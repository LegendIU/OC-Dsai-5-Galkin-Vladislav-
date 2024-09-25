#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 0;
void* thread_func(void* arg) {
    for (int i = 0; i < 100000; i++) {
        counter++;
    }
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

    printf("Final counter value: %d\n", counter);
    sleep(3);

    return 0;
}
