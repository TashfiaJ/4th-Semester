#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<semaphore.h>

#define row 3
#define column 10
sem_t lock; // semaphore
int count; // global variable
pthread_t threads[row];

int matrix[row][column];

void* doStuffWithSync(void* val){
	int roww = *(int*)val;
    sem_wait(&lock);
	for(int i=0; i<column; i++){
		if(matrix[roww][i]==1){
		       	count++;	
		}
	}
    sem_post(&lock);
}

int main()
{
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    sem_init(&lock, 0, 1);

    for(int i=0;i<row;i++)
    {
        int* save_i = (int*)malloc(sizeof(int));
		*save_i=i;
		pthread_create(&threads[i], NULL, doStuffWithSync, (void*)save_i);
    }
    for(int i=0; i<row; i++) pthread_join(threads[i],NULL);
    printf("Number of 1's(Synchronization): %d\n",count);
}

