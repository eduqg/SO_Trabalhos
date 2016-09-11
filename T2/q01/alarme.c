/*============================================================================*/
/*Name        : alarme.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


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

		printf("ERROR: Child Process has not been created\n");
	}
	else
	{
		pause();
	}


	return 0;
}
