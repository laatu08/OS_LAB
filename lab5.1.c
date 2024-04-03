// Fork system call
// man 2 fork

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    pid_t q=fork();

    if(q<0){ // For error
        printf("Error/n");
    }
    else if(q==0){ // For child process
        printf("Child having pid %d\n",getpid());
        printf("Parent having pid %d\n",getppid());
    }
    else{ // For parent process
        printf("Parent having pid %d\n",getpid());
        printf("Child having pid %d\n",q); // fork will return the pid of child process created during parent process
    }
    printf("Common Segment\n");
    return 0;
}