// Inter-process communication using popen
// man popen

#include<stdio.h>
#include<string.h>

int main(){
    FILE *rd;
    char buffer[50];

    // use to print string in buffer
    sprintf(buffer,"Hello world");

    // first argument is process and second is mode
    // rd=popen("wc -c","w"); // -c return number of character
    rd=popen("wc -w","w"); // -w return number of word

    fwrite(buffer,sizeof(char),strlen(buffer),rd);
    pclose(rd);

}