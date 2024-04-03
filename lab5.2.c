// child process has another child process
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
        printf("I am child\n");
        pid_t p=fork();
        if(p<0){
            printf("Child Error\n");
        }
        else if(p==0){
            printf("Child Child\n");
        }
        else{
            printf("Child Parent\n");
        }
    }
    else{ // For parent process
        printf("I am parent\n");
    }
    printf("Common Segment\n");
    return 0;
}