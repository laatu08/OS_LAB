#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int res,n;

    res=open("fifo1",O_WRONLY); //open in write only mode
    // res=open("fifo1",O_NONBLOCK,O_WRONLY); //run in non blocked mode

    // Send the message using write
    write(res,"Message",7);
    printf("Sender Process having PID %d sent the data\n",getpid());
}

// to compile run gcc -o sender sender.c
// then run ./sender