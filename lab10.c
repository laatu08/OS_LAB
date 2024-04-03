// Create Threads
// man pthread_create

// Thread is a part of process

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *args){
    printf("Inside Thread\n");
    for(int i=0;i<5;i++){
        printf("%d\n",i);
        sleep(1); //Delay every output by 1sec
    }
}

int main(){
    pthread_t a_thread;  //Thread declaration

    // the thread created will be storedin a_thread.
    // the first null represent its attribute nad null mean default attribute
    // thread_function is action to be performed by the thread
    // the last null represent the parameter passed to be passed in thread_function
    pthread_create(&a_thread,NULL,thread_function,NULL); //Thread is created
    
    // Null represent the variable which will store a value return by thread
    pthread_join(a_thread,NULL); //Process waits for thread (thread_function) to finish

    printf("Inside Main Program\n");

    for(int j=20;j<25;j++){
        printf("%d\n",j);
        sleep(1); //Delay every output by 1sec
    }
}


// Note: to compile any program which involves creation of thread(s) use pthread library (lpthread). 
// Suppose the above program is named "Thread.c" then to compile write
// gcc Thread.c -lpthread