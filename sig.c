#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>


int main(){
	int pid;
	
	if((pid = fork()) == 0){//child code
	
		while(1){
			printf("Child runnig...\n");
			sleep(1);
		}
		
		printf("Child stopping\n"); //This won't show beacause the parent process killed the child process
		
	}
	
	else if(pid < 0){
		printf("Fork failed\n");
		exit(1);
	}
	
	else{//parent code
	
		printf("Parent started.. sleeping for 5 secs\n");
		sleep(5);
		printf("Parent sending SIGKILL signal for child.\n");
		kill(pid, SIGKILL);
		
	}

	return 0;
}


// SIGINT (Interrupt signal ... ctrl+c)
// SIGSTOP (Suspend process)
// SIGCONT (Continue process)
// SIGKILL
