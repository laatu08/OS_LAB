// Process(threads) Synchronization using Semaphores

// sem_t -> datatype to store semaphore
// sem_init() -> use initialise the declare semaphore
// sem_wait() -> wait in semaphore
// sem_post() -> signal in semaphore

// sem_wait()
// Critical Section
// sem_post()

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include<semaphore.h>

int share = 1; // Shared variable
sem_t s; // semaphore variable

void *func1()
{
    int x;

    sem_wait(&s);

    x = share;
    printf("Thread1 reads the value of share variable as %d\n", x);
    x++;
    printf("Local updation by Thread1: %d\n", x);
    sleep(1);
    share = x;
    printf("Value of shared variable updated by Thread1 is : %d\n", share);

    sem_post(&s);
}

void *func2()
{
    int x;

    sem_wait(&s);

    x = share;
    printf("Thread2 reads the value of share variable as %d\n", x);
    x--;
    printf("Local updation by Thread2: %d\n", x);
    sleep(1);
    share = x;
    printf("Value of shared variable updated by Thread2 is : %d\n", share);

    sem_post(&s);
}

int main()
{
    // &s -> address of variable
    // second argument: 0(for threads) and 3(for process)
    // third argument(initial value): 1(in used) and 0(it is free to use)
    sem_init(&s,0,1);

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", share);
}