#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct my_msg
{
    long int msg_type;
    char some_text[BUFSIZ];
};

int main()
{
    int running = 1;
    int msgid;
    struct my_msg some_data;

    // 0 means that message will be retrived in the same order
    long int msg_to_rec=0;

    msgid = msgget((key_t)12345, 0666 | IPC_CREAT);

    while (running)
    {
        // msg_to_rec = 0 means that it will return first message
        // msg_to_rec > 0 means that it will return first message of same type
        msgrcv(msgid,(void *)&some_data,BUFSIZ,msg_to_rec,0);
        printf("Data received: %s\n",some_data.some_text);
        if(strncmp(some_data.some_text,"end",3)==0){
            running=0;
        }
    }

    // Delete the message queue
    msgctl(msgid,IPC_RMID,0);
}
