#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum) {
    printf("Child received signal: %d\n", signum);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) { // Child process
        signal(SIGUSR1, signal_handler);
        pause(); // Περιμένει το σήμα
    } else { // Parent process
        sleep(1);
        kill(pid, SIGUSR1);
        printf("Parent sent signal to child\n");
    }
    return 0;
}
