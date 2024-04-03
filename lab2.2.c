// open() system call (file not created)
// man 2 open

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int n;
    char buf[50];

    // int fd;
    // // first argument is file name and second argument indicate the mode in which we will opoen the file
    // fd=open("test.txt",O_RDONLY);

    n=read(0,buf,20);

    int fd1;
    fd1=open("target2",O_CREAT|O_WRONLY,0642);
    write(fd1,buf,n);
}