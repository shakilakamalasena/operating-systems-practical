#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * thread_job();

int main(){

	pthread_t job1, job2;
	
	pthread_create(&job1, NULL, &thread_job, NULL);
	pthread_create(&job2, NULL, &thread_job, NULL);
	
	
	//pthread_join(job1, NULL);
	//pthread_join(job2, NULL);
}

void * thread_job(){
	while(1){
		printf("Inside the thread.\n");
		sleep(1);
	}
}
