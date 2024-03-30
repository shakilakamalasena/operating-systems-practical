#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(){

	pid_t pid; 
	char string[] = "Hello world!";
	
	int pipefd[2];
	int ret = pipe(pipefd);
	printf("Return value of pipe: %d\n", ret);
	if(ret != 0){
		exit(1);
	}
	
	if((pid = fork()) == 0){
		
		close(pipefd[0]);
		write(pipefd[1], string, strlen(string)+1);
		close(pipefd[1]);
		
	}else if(pid < 0){
		printf("Fork failed\n");
		exit(0);
	}else{
		char incoming_data[20];
		
		close(pipefd[1]);
		read(pipefd[0], incoming_data, strlen(string)+1);
		close(pipefd[0]);
		
		printf("Incoming data from child to parent: %s\n", incoming_data);
	}
	return 0;
}
