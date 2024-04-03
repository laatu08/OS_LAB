// Pass parameter to a thread

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int num[2]={3,5};

void *thread_function(void *args){
    printf("Inside Thread\n");
    int *x=args;
    int sum=x[0]+x[1];
    printf("Sum is %d\n",sum);
    
    // pthread_exit act as return
    pthread_exit("Sum calculated");
}

int main(){
    pthread_t a_thread;  //Thread declaration
    void *result;

    // the thread created will be storedin a_thread.
    // the first null represent its attribute nad null mean default attribute
    // thread_function is action to be performed by the thread
    // the last value represent the parameter passed to be passed in thread_function
    pthread_create(&a_thread,NULL,thread_function,(void *)num); //Thread is created
    
    // result represent the variable which will store a value return by thread
    pthread_join(a_thread,&result); //Process waits for thread (thread_function) to finish

    printf("Inside Main Program\n");
    printf("Thread returned: %s\n",(char *)result);
}