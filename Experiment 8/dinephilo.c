#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <conio.h>

sem_t room;
sem_t chopsticks[5];

void *philosopher(void *);
void eat(int);

int main()
{
    int i, a[5];
    pthread_t threads[5];

    sem_init(&room, 0, 4);

    for (i = 0; i < 5; i++)
        sem_init(&chopsticks[i], 0, 1);
    for (i = 0; i < 5; i++)
    {
        a[i] = i;
        pthread_create(&threads[i], NULL, philosopher, (void *)&a[i]);
    }
    for (i = 0; i < 5; i++)
        pthread_join(threads[i], NULL);
}

void *philosopher(void *num)
{
    int phil = *(int *)num;

    sem_wait(&room);
    printf("\nPhilosopher %d has entered room", phil);
    sem_wait(&chopsticks[phil]);
    sem_wait(&chopsticks[(phil + 1) % 5]);

    eat(phil);
    sleep(2);
    printf("\nPhilosopher %d has finished eating", phil);

    sem_post(&chopsticks[(phil + 1) % 5]);
    sem_post(&chopsticks[phil]);
    sem_post(&room);
    getch();
}

void eat(int phil)
{
    printf("\nPhilosopher %d is eating", phil);
}