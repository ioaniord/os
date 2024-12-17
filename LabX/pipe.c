#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];           // 0: Read end, 1: Write end
    char buffer[100];        // Μνήμη για το μήνυμα που θα διαβάσει το παιδί
    char message[] = "Hello from parent!"; // Μήνυμα προς αποστολή

    // Δημιουργία του pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork(); // Δημιουργία child process

    if (pid < 0) {
        perror("fork"); // Σφάλμα στη δημιουργία διεργασίας
        return 1;
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Κλείνουμε το write end (δεν γράφει το παιδί)
        read(pipefd[0], buffer, sizeof(buffer)); // Διαβάζουμε από το pipe
        printf("Child received: %s\n", buffer);  // Εκτύπωση του μηνύματος
        close(pipefd[0]); // Κλείνουμε το read end
    } else { // Parent process
        close(pipefd[0]); // Κλείνουμε το read end (δεν διαβάζει ο γονέας)
        printf("Parent sending: %s\n", message);
        write(pipefd[1], message, strlen(message) + 1); // Γράφουμε στο pipe
        close(pipefd[1]); // Κλείνουμε το write end
    }

    return 0;
}
