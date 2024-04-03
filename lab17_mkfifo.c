// Inter-process communication using mkfifo
// man 1 mkfifo
// man 3 mkfifo

// create name pipe and use exactly like pipe
// success=0 else -1

// fifo named pipe works in blocked mode which mean that both reader and writer process must be present at their respective end

// Program 1: Create a named pipe
// Program 2: Create a sender process (write into pipe)
// Program 3: Create a receiver process (read from pipe)

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int res;
    res=mkfifo("fifo1",0777); // Creates a named pipe with the name fifo1

    printf("Named pipe created\n");
}

// Run the following code by ./a.out
// ls fifo1
// ls -l fifo1 -> it gives the pipe