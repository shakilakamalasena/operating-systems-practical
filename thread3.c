#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define THREAD_COUNT 10
#define START_NUMBER 1
#define END_NUMBER 100000

void * thread_job(void * input);

typedef struct{
	int thread_id;
	int start_value;
	int end_value;
}pthread_input;

long sum = 0;
pthread_mutex_t mutex;
 
int main(){

	pthread_t thread[THREAD_COUNT];
	pthread_input thread_inputs[THREAD_COUNT];
	
	pthread_mutex_init(&mutex, NULL);
	
	int val = START_NUMBER;
	int increment = (END_NUMBER - START_NUMBER)/THREAD_COUNT;
	
	for(int i=0; i<THREAD_COUNT; i++){
		thread_inputs[i].thread_id = i+1;
		thread_inputs[i].start_value = val;
		thread_inputs[i].end_value = val + increment;
		val += increment + 1;
		
		pthread_create(&thread[i], NULL, &thread_job, &thread_inputs[i]);
	}
	
	for(int i=0; i<THREAD_COUNT; i++){
		pthread_join(thread[i], NULL);
	}
	
	pthread_mutex_destroy(&mutex);
	
	printf("Sum = %ld\n", sum);
}

void * thread_job(void * input){
	int thread_id = ((pthread_input *)input)->thread_id;
	int start_value = ((pthread_input *)input)->start_value;
	int end_value = ((pthread_input *)input)->end_value;
	//printf("Thread id: %d\n", thread_id);
	//printf("Start value: %d\n", start_value);
	//printf("End value: %d\n", end_value);
	
	for(int i = start_value; i<=end_value; i++){
		pthread_mutex_lock(&mutex);
		sum+= i;
		pthread_mutex_unlock(&mutex);
	}
}






















