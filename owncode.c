#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
 int name;
 for (int i=1;i<5;i++){
  pid_t pid = fork();
  
  if (pid == 0){
   printf("Enter child name: ");
   scanf("%d", &name);
   printf("Child process=> PPID=%d,PID=%d\n", getppid(), getpid());
   
   exit(0);
  }
  else{
   printf ("Parent process => PID=%d\n", getpid());
   printf ("Waiting for child processes to finish...\n");
   wait(NULL);
   printf("child process finished.\n");
  }
 }
 return EXIT_SUCCESS;
}
