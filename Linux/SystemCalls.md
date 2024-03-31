### Process Management:

- fork(): Create a new process.
- exec(): Execute a new program in the current process.
- wait(), waitpid(): Wait for child process to terminate.
- exit(): Terminate the current process.
- getpid(): Get the process ID of the current process.
- getppid(): Get the parent process ID.

### File System:

- open(), close(): Open and close files.
- read(), write(): Read from and write to files.
- lseek(): Move the file pointer within a file.
- stat(), fstat(): Get file status.
- mkdir(), rmdir(): Create and remove directories.
- rename(), unlink(): Rename and delete files.

### Inter-Process Communication:
- pipe(), pipe2(): Create an unnamed pipe.
- shmget(), shmat(): Create and attach shared memory segments.
- msgget(), msgsnd(), msgrcv(): Create and send/receive messages to/from message queues.
- semget(), semop(): Create and perform operations on semaphores.

### Network Communication:
- socket(), bind(), listen(), accept(), connect(): Create and manage network sockets.
- send(), recv(): Send and receive data over sockets.
- getaddrinfo(), getnameinfo(): Resolve addresses and names.

### Time:
- gettimeofday(): Get current time.
- time(): Get current time in seconds since the Epoch.
- clock_gettime(): Get time based on a specified clock.

### User and Group Management:
- getuid(), geteuid(), getgid(), getegid(): Get user and group IDs.
- setuid(), setgid(): Set user and group IDs.

### System Information:
- uname(): Get system information.
- gethostname(): Get the hostname of the machine.