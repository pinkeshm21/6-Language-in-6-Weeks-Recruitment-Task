#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *myThreadFun( void *fun)
 {

	int msec;
	clock_t start = clock(), diff;
	
	int i=0;
	do{
		diff = clock() - start;
		msec = diff * 1000 / CLOCKS_PER_SEC;
		i++;
	}while(msec!=1000);

	printf("Number is %d", i);
	return NULL;
	
    }  
 int main()   
 {  pthread_t thread_id;
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    exit(0);
 }