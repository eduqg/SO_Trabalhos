#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int main(int argc, char** argv)
{

	const int number_of_threads = atoi(argv[1]);

	if(argc != 2 || number_of_threads > 10)
	{
		printf("Usage: %s <number_of_threads>\n\n", argv[0]);
		printf("Ps: The number of threads must be smaller than 10.\n");
		exit(1);
	}	
		
	printf("%d\n", atoi(argv[1]));




	return 0;
}