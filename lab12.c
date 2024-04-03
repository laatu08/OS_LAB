// Simulation of race condition

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int share = 1; // Shared variable

void *func1()
{
    int x;
    x = share;
    printf("Thread1 reads the value of share variable as %d\n", x);
    x++;
    printf("Local updation by Thread1: %d\n", x);
    sleep(1);
    share = x;
    printf("Value of shared variable updated by Thread1 is : %d\n", share);
}

void *func2()
{
    int x;
    x = share;
    printf("Thread2 reads the value of share variable as %d\n", x);
    x--;
    printf("Local updation by Thread2: %d\n", x);
    sleep(1);
    share = x;
    printf("Value of shared variable updated by Thread2 is : %d\n", share);
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", share);
}