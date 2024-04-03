// dup() system call
// man 2 dup

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main(){
    int fd;
    fd=open("dup",O_RDONLY);
    printf("Old fd is %d\n",fd);
    
    int fd1;
    // fd1=dup(fd);
    fd1=dup2(fd,7);
    printf("New fd is %d\n",fd1);
}