#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<semaphore.h>

#define row 3
#define column 5000000
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
            //scanf("%d", &matrix[i][j]);
            matrix[i][j]=1;
        }
    }
    sem_init(&lock, 0, 1);
    clock_t begin_time = clock();
    for(int i=0;i<row;i++)
    {
        int* save_i = (int*)malloc(sizeof(int));
		*save_i=i;
		pthread_create(&threads[i], NULL, doStuffWithSync, (void*)save_i);
    }
    for(int i=0; i<row; i++) pthread_join(threads[i],NULL);
    clock_t end_time = clock();
    printf("Number of 1's(Synchronization): %d Time=%.2lf\n",count, (double)(end_time-begin_time)/CLOCKS_PER_SEC);
}

