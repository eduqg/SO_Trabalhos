/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc > 2)
	{
		printf("args 0: %s\n", argv[0]);
		printf("args 1: %s\n", argv[1]);
		printf("args 2: %s\n", argv[2]);

		



	}
	else
	{
		printf("Usage: %s <path> <string> <max_lines>\n", argv[0]);
		exit(-1);
	}


		
	return 0;
}
