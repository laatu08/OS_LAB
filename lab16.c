// Inter-process communication using pipe
// man pipe
// man 2 pipe

// pipe create an unidirectional communication line
// Writing end of pipe -> fd[1]
// Reading end of pipe -> fd[0]

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int fd[2],n;
    char buffer[100];
    pid_t p;

    pipe(fd);
    p=fork();

    // parent process will be sender and child process will be receiver

    if(p>0){ // Parent(sender)
        printf("Passing value to child\n");
        // sender data using write
        write(fd[1],"hello\n",6);
    }
    else{ // Child(receiver)
        printf("Child received data\n");
        n=read(fd[0],buffer,100);
        // write on the screen
        write(1,buffer,n);
    }
}