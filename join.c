#include <stdio.h>
#include <pthread.h>

// Create a pointer function which will print child process when called
void *child_thread(void *arg) {
    printf("Child thread\n");

    // pthread_exit() is use to exit the function 
    pthread_exit(NULL);
}

int main() {
    // create a variable of type pthread_t , it will store the id child thread
    pthread_t thread;

    // Create a new thread-
    // &thread --> location which will store the id of newly created thread
    // NULL --> use to specify thread attribute
    // child_thread --> function which the new thread created will run
    // NULL --> argument passed to the function child_thread
    int ret = pthread_create(&thread, NULL, child_thread, NULL);

    // ret will store the result passed by pthread_create
    // If successful , it will return 0, else it will return non-zero value

    // If thread creation is not successful, ret != 0
    if (ret) {
        printf("Thread creation failed\n");
        return 1;
    }

    // Parent process will continue to execute
    printf("Parent thread\n");

    // Joining the child thread
    // Here the child thread created will run and halt the parent thread execution until it is finish
    pthread_join(thread, NULL);
    
    // parent process continue to execute
    printf("Parent thread again\n");
    
    return 0;
}
