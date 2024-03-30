#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define THREAD_COUNT 10

void * thread_job(void * input);

typedef struct{
	int thread_id;
}pthread_input;


int main(){

	pthread_t thread[THREAD_COUNT];
	pthread_input thread_inputs[THREAD_COUNT];
	
	for(int i=0; i<THREAD_COUNT; i++){
		thread_inputs[i].thread_id = i+1;
		pthread_create(&thread[i], NULL, &thread_job, &thread_inputs[i]);
	}
	
	for(int i=0; i<THREAD_COUNT; i++){
		pthread_join(thread[i], NULL);
	}
	
}

void * thread_job(void * input){
	int thread_id = ((pthread_input *)input)->thread_id;
	printf("Thread id: %d\n", thread_id);
}
