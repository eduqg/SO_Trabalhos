#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(void)
{
	
	pid_t PID;

	PID = fork();

		
	if(PID == 0)
	{
		printf("Child Process\n");
		sleep(5);
		kill(PID, SIGALRM);
	}
	else if(PID < 0)
	{
		
		printf("Process failed\n");
	}
	else
	{
		pause();
	}


	return 0;
}
