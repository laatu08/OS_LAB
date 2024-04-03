// Inter-process communication using Message Queue
// man msgget
// man msgsnd
// man msgrcv
// man msgctl

// msgget() -> use to create a message queue
// msgsnd() -> use to add message to message queue
// msgrcv() -> use to retrieve message from message queue
// msgctl() -> use to control function such as delete message queue

// Program 1 -> sender
// Program 2 -> receiver

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// #define MAX_TEXT 50
#define MAX_TEXT 10

struct my_msg
{
    long int msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int running = 1;
    int msgid;
    struct my_msg some_data;
    char buffer[20];

    // create a message queue
    msgid = msgget((key_t)12345, 0666 | IPC_CREAT);

    // Check if the message queue is created or not
    if (msgid == -1)
    {
        printf("Error in creating queue\n");
    }

    while (running)
    {
        printf("Enter some text\n");

        // receive data from user and store in buffer of length 20 from stdin(standard input device i.e. keyboard)
        fgets(buffer, 20, stdin);

        some_data.msg_type = 1;                            
        strcpy(some_data.some_text, buffer);

        // 0 will waith till the message is written and 1 will return immediately(use to control process)
        if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
        {
            printf("Message not send\n");
        }

        if (strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
    }
}
