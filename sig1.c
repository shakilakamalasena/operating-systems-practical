#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void handler_SIGNHUP(int signal){
	printf("CHILD: I have received a SIGNHUP\n");
}

void handler_SIGINT(int signal){
	printf("CHILD: I have received a SIGINT\n");
}

void handler_SIGQUIT(int signal){
	printf("CHILD: I have received a SIGQUIT\n");
}

int main(){

	int pid;
	
	if((pid = fork()) == 0){
		printf("==== CHILD ====\n");
		
		signal(SIGHUP, handler_SIGNHUP);
		signal(SIGINT, handler_SIGINT);
		signal(SIGQUIT, handler_SIGQUIT);
		
		for(;;);
		
	}
	
	else if(pid > 0){
		
		printf("==== PARENT ====\n");
		printf("PARENT: Sending SIGHUP\n");
		kill(pid, SIGHUP);
		sleep(2);
		
		printf("PARENT: Sending SIGINT\n");
		kill(pid, SIGINT);
		sleep(2);
		
		printf("PARENT: Sending SIGQUIT\n");
		kill(pid, SIGQUIT);
		sleep(2);
		
	}
	
	else{
	
		printf("Fork error.\n");
		exit(1);
		
	}

}
