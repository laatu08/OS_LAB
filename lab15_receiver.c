// Inter-process communication using popen
// man popen

#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
    FILE *rd;
    char buffer[50];

    // use to print string in buffer
    sprintf(buffer,"Hello world");

    // first argument is process and second is mode
    rd=popen("ls","r"); // ls return data currrent directory

    fread(buffer,sizeof(char),20,rd);

    write(1,buffer,20);
    printf("\n");

    pclose(rd);

}