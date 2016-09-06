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

	/*Creates the intentificator of process */
	int PID;

	/*Reply a process from parent*/
	PID = fork();

	/*If fork doesn't work*/
	if(PID == 0)
	{
		printf("Child process\n");
		sleep(5);
		kill(PID, SIGALRM);
	}
	else if(PID < 0)
	{
		/*Fork doesn't worked*/
		printf("Process failed\n");
	}
	else
	{
		pause();
	}


	return 0;
}
