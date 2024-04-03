// Write System calls
// man write
// man 2 write

#include<unistd.h>
#include<stdio.h>
int main(){
    // fd: 0(input device), 1(output device) and 2(error(output device))
    int w=write(1,"Hello\n World",6);
    printf("%d\n",w);
}