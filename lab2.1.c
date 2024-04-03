// open() system call (file already created)
// man 2 open

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int n;
    char buf[50];

    int fd;
    // first argument is file name and second argument indicate the mode in which we will opoen the file
    fd=open("test.txt",O_RDONLY);

    n=read(fd,buf,10);

    write(1,buf,n);
}