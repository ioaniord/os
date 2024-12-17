#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) { // Child process
            printf("Child Process PID: %d\n", getpid());
            return 0; // Το child τερματίζει εδώ
        }
    }
    return 0; // Αν θέλαμε ο γονέας να εκτπώνει το PID του πριν το return, print(..)
}

