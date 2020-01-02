#include<stdio.h>
#include<unistd>
#include<stdlib>
#include<sys/types.h>

int main(){
	
	int pidefd[2];
	char message[20];
	int pid;
	
	
	if(pipe(pipefd)<0){
		
		printf("Pipe not working");
		exit(EXIT_FAILURE);
	}else{
		pid=fork();
		if(pid<0){
			
			printf("Fork is not working");
			exit(EXIT_FAILURE);
		}if(pid>0){
			write(pipefd[1],"hello from parent\0",18);
			close(pipefd[1]);
			exit(0);
		}else{
			read(pipefd[0],message,18);
			close(pipefd[0]);
			printf("%s",message);
			exit(0);
			
			
		}
		
		
		
		
		
		
	}
	
	
	
	
}
