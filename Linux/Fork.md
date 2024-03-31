The fork() function in Linux is a system call used for creating a new process, which is called the child process. Here's how it works:

- When fork() is called, a new child process is created that is an exact copy of the calling (parent) process. This includes copies of the parent process's memory, file descriptors, and other attributes.

- The child process starts executing from the point where fork() was called. This means that the child process will execute the same code as the parent process unless there's a conditional branch based on the return value of fork().

- In the parent process, fork() returns the process ID (PID) of the newly created child process. In the child process, fork() returns 0 to indicate that it's the child process. If there's an error, fork() returns -1.

- After fork() returns, both the parent and child processes continue executing independently. They have separate memory spaces, so changes made by one process do not affect the other.

- It's important to note that while the child process is a copy of the parent process, they are separate entities and can run concurrently. This allows for parallelism and multitasking in Linux systems.

```cpp
#include <iostream>
#include <unistd.h> // For fork() function

int main() {
    pid_t pid = fork(); // Creating a new process

    if (pid < 0) {
        // Fork failed
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child process: PID = " << getpid() << std::endl;
        // Child-specific code can go here
    } else {
        // Parent process
        std::cout << "Parent process: PID = " << getpid() << ", Child PID = " << pid << std::endl;
        // Parent-specific code can go here
    }

    // Both parent and child processes will reach this point
    return 0;
}

```