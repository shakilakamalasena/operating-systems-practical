// Program to input values to the thread


#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * thread_job(void * input);

typedef struct{
	int thread_id;
}pthread_input;

int main(){

	pthread_t job1, job2;
	pthread_input job1_input, job2_input;
	
	job1_input.thread_id = 1;
	job2_input.thread_id = 2;
	
	pthread_create(&job1, NULL, &thread_job, &job1_input);
	pthread_create(&job2, NULL, &thread_job, &job2_input);
	
	
	pthread_join(job1, NULL);
	pthread_join(job2, NULL);
}

void * thread_job(void * input){
	int thread_id = ((pthread_input *)input)->thread_id;
	printf("Thread id: %d\n", thread_id);
}
