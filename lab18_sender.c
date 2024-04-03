// Inter-process communication using Shared Memory
// man shmget
// man shmat

// sender will write in shared memory and receiver will read from shared memory but it is not part of sender or receiver

// shmget() -> is used to create the shared memory segment
// shmat() -> is used to attach the shared segment with the address space of the process

// Program 1 - the sender
// Program 2 - the receiver

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;

    // Create shared memory segment with key 1122
    // IPC_CREAT is use to create shared memory haivng key=1122, size=1024, and permission=0666
    shmid = shmget((key_t)1122, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);

    // Process attached to shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    // This print the address where the segment is attached
    printf("Process attached at %p\n", shared_memory);

    printf("Enter some data to write to shared memory\n");

    // Get some input from user
    read(0, buff, 100);

    // Data writtent o shared memory
    strcpy(shared_memory,buff);

    printf("You wrote : %s\n",(char *)shared_memory);
}