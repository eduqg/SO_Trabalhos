/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <sys/stat.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char **argv)
{

	if(argc == 2)
	{	

	    struct stat t_stat;
	    stat(argv[1], &t_stat);
	    struct tm * timeinfo = localtime(&t_stat.st_ctime); // or gmtime() depending on what you want
	    printf("File time and date: %s", asctime(timeinfo));

	}

    return 0;


}

