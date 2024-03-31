

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2]; // File descriptors for the pipe
    pid_t pid;
    char buffer[50];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close the write end of the pipe in the child

        // Read data from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received message: %s\n", buffer);

        close(pipefd[0]); // Close the read end of the pipe in the child
    } else { // Parent process
        close(pipefd[0]); // Close the read end of the pipe in the parent

        // Write data to the pipe
        printf("Enter a message to send to child: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(pipefd[1], buffer, sizeof(buffer));

        close(pipefd[1]); // Close the write end of the pipe in the parent
    }

    return 0;
}

```