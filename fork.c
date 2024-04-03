#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Original process ID: %d\n",getpid());

    // We declare a pid_t type variable (can also use int)
    // fork() will create two processes, one will be child and another parent
    // fork() will return some value depending on the state of operation
    pid_t pid = fork();

    // First Parent process will run (if fork is successful), and then child process will run and return a value off 0
    if (pid == 0)
    {
        // getpid() will give the process id of current(child) process
        // getppid() wi1l give the process id of current(child) process's parent process(original process)
        printf("Child process: PID=%d, Parent PID=%d\n", getpid(), getppid());
    }

    // Parent process(original) will run, it return a value greater than 0
    else if (pid > 0)
    {
        // Here we will get the process id of original(parent) process
        printf("Parent process: PID=%d\n", getpid());
    }

    // If the fork is unsuccessful, it will return -1
    else
    {
        printf("Fork failed!\n");
        return 1;
    }

    return 0;
}
