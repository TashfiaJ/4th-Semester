#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include<string.h>

#define S 30

int readcount, writecount, count=0;                 
sem_t rmutex, wmutex, readTry, resource;
pthread_t threads[S];

void reader(void* rd)
{   
    //entry section
    sem_wait(&readTry);
    sem_wait(&rmutex);
    readcount++;
    if(readcount==1)
    {
        sem_wait(&resource);
    }
    sem_post(&rmutex);
    sem_post(&readTry);

    //critical section
    printf("\n%d reader is reading value=%d\n",*(int *)rd, count);
    sem_wait(&rmutex);
    readcount--;
    if(readcount==0)
    {
        sem_post(&resource);
    }
    sem_post(&rmutex);

}

void writer(void *wr)
{
    sem_wait(&wmutex);
    writecount++;
    if(writecount==1)
    {
        sem_wait(&readTry);
    }
    sem_post(&wmutex);
    sem_wait(&resource);
    count++;
    printf("\n%d writer is writing value=%d\n", *(int *)wr, count);
    sem_post(&resource);

    sem_wait(&wmutex);
    writecount--;
    if (writecount == 0)        
    {
        sem_post(&readTry);
    }
    sem_post(&wmutex);
}

int main()
{
    sem_init(&rmutex,0,1);
    sem_init(&wmutex,0,1);
    sem_init(&readTry,0,1);
    sem_init(&resource,0,1);

    for(int i=0;i<S;i++)
    {
        int  *a = (int*)malloc(sizeof(int));
        *a=i;
        
        if(!((rand()%500+1)%2))
        {
            pthread_create(&threads[i],NULL,(void *)reader,a);
        }
        else{
            pthread_create(&threads[i],NULL,(void *)writer,a);
        }
    }

    for(int i=0;i<S;i++)
    {
        pthread_join(threads[i],NULL);
    }
}