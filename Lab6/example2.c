#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t signal_received = 0;

void handle_signal(int signum) {
    switch (signum) {
        case SIGUSR1:
            printf("Received SIGUSR1\n");
            break;
        case SIGUSR2:
            printf("Received SIGUSR2\n");
            break;
        default:
            fprintf(stderr, "Caught unexpected signal: %d\n", signum);
    }
    signal_received |= 1 << signum;
}

int main() {
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    char input[256];
    printf("Enter a number: ");

    while (fgets(input, sizeof(input), stdin)) {
        long num = strtol(input, NULL, 10);

        if (num > 0) {
            if (input[0] == '-') {
                kill(getpid(), SIGUSR1);
            } else {
                kill(getpid(), SIGUSR2);
            }
        } else {
            printf("Invalid input\n");
        }

        printf("Signal received: %s\n", signal_received ? "SIGUSR1" : "None");
        signal_received = 0;
    }

    return 0;
}
