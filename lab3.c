// lseek() system call
// man 2 lseek

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int n, f, f1;
    char buf[100];

    f=open("seeking",O_RDWR); //1234567890qwertyuiop0987654321

    // Without lseek()
    // read(f,buf,10);
    // write(1,buf,10); //1234567890
    
    // read(f,buf,10);
    // write(1,buf,10); //qwertyuiop


    // With lseek()
    read(f,buf,10);
    write(1,buf,10); //1234567890

    lseek(f,10,SEEK_CUR);

    read(f,buf,10);
    write(1,buf,10); //0987654321

}