#include <stdlib.h>
#include <stdio.h>
#include "thread.h"

int main(int argc, char **argv)
{
	
	
	if(argc > 2)
	{

		ARGS *args;
		const int SIZE = atoi(argv[1]);

		if(SIZE > 100)
		{
			printf("ERROR: The limit of size vector is 100\n");
			exit(0);
		}	

		args = (ARGS *) calloc(SIZE, sizeof(ARGS));
		
		args -> x = initialize_vector(SIZE, &(*argv));

		print_vector(SIZE, args -> x);

		args -> w = set_vector(SIZE, args -> x);

		print_vector(SIZE, args -> w);

		args -> w = calculate_bigger(SIZE, args);




	}	
	else
	{
		printf("Usage: %s <num_inputs> <num_1> ... <num_n>\n", argv[0]);
		exit(-1);
	}	

	return 0;
}