#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void handle_interrupt(int signal);

int main(){
	
	if(signal(SIGINT, &handle_interrupt) == SIG_ERR){
		printf("Failed to initialize signal handler.\n");
		exit(1);
	}

	while(1){
		printf("Running...\n");
		sleep(1);
	}

	return 0;
}

void handle_interrupt(int signal){
	printf("You pressed CTRL+C\n");
}
