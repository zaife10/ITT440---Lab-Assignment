#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void Done(){	//THIS IS PARENT
	//printf("Waiting for all task to inserted...\n");
	//wait(NULL);
	printf("Job is done. \n");
}

void Task(){	//THIS IS CHILD
	char task[20];

	printf("What is your task ? : ");
	fgets(task,20,stdin);
	printf("My task is %s", task);
	//getchar();
}

int main(void){
	for(int x = 0; x <=  3; x++){
		pid_t pid = fork();
		
		if(pid == 0){
			Task();
			exit(EXIT_SUCCESS);
		}
	
		else{
			printf("Waiting for all task to be inserted...\n");
			wait(NULL);
		}
	}
	Done();
	return 0;
}
