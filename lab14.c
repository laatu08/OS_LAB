// Process Synchronization using Mutex Lock

// pthread_mutex_t
// pthread_mutex_init()
// pthread_mutex_lock()
// pthread_mutex_unlock()

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int share = 1; // Shared variable
pthread_mutex_t l; // lock variable

void *func1()
{
    int x;

    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("Thread1 acquired lock\n");

    x = share;
    printf("Thread1 reads the value of share variable as %d\n", x);
    x++;
    printf("Local updation by Thread1: %d\n", x);
    sleep(1);
    share = x;
    printf("Value of shared variable updated by Thread1 is : %d\n", share);

    pthread_mutex_unlock(&l);
    printf("Thread1 release the lock\n");
}

void *func2()
{
    int x;

    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("Thread2 acquired lock\n");

    x = share;
    printf("Thread2 reads the value of share variable as %d\n", x);
    x--;
    printf("Local updation by Thread2: %d\n", x);
    sleep(1);
    share = x;
    printf("Value of shared variable updated by Thread2 is : %d\n", share);

    pthread_mutex_unlock(&l);
    printf("Thread2 release the lock\n");
}

int main()
{
    pthread_mutex_init(&l,NULL); //Initializing mutex lock

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", share);
}