// Read system call
// man 2 read

#include<stdio.h>
#include<unistd.h>

int main(){
    int n;
    char b[30];

    // 0 because we have to read from keyboard(input device)
    // n=read(0,b,10);
    n=read(0,b,30);

    // 1 because we have show the result in screen(output device)
    // write(1,b,10);
    write(1,b,n);
}