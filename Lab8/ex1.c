#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *message = (char *)malloc(50 * sizeof(char));

    sprintf(message, "This is a message in the heap!");

    printf("PID: %d\n", getpid());
    printf("Message in the heap: %s\n", message);

    while (1) {
        sleep(1);
    }

    free(message);

    return 0;
}
