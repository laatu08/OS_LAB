#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
    int res, n;
    char buffer[100];

    res=open("fifo1",O_RDONLY);
    // res=open("fifo1",O_NONBLOCK,O_RDONLY);

    n=read(res,buffer,100);
    
    printf("Reader process having pid %d started\n",getpid());
    printf("Data received by receiver %d is: %s\n",getpid(),buffer);
}

// to compile gcc -o receiver receiver.c
// then ./receiver

// To run both together  ./sender & ./receiver