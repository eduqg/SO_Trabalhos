#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* More info : http://stackoverflow.com/questions/9289234/c-process-fork-and-sigalarm */

int main(void)
{
	/*
		fork()  creates  a new process by duplicating the calling process. 
		The new process is referred to as the child process.
	*/
	int PID;
	while(1){
		PID = fork();


		if(PID == 0)
		{
			//child process
			printf("Child process\n");
			sleep(5);
			/*

			*/
			kill(PID, SIGALRM);
		} 
		else if(PID == -1)
		{
			//error has ocurred

			printf("Process failed\n");
		}
		else
		{

			//parent process
			pause();
		}
	}
	return 0;
}
