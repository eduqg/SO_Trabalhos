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


		args = (ARGS *) malloc(sizeof(ARGS));

		args -> x = initialize_vector_x(SIZE, &(*argv));
		printf("Vetor X: ");
		print_vector(SIZE, args -> x);

		args -> w = initialize_vector_w(SIZE);
		printf("Vetor W: ");
		print_vector(SIZE, args -> w);

		args -> w = calculate_bigger(SIZE, args);

		printf("Vetor X: ");
		print_vector(SIZE, args->x);

		printf("Vetor W: ");
		print_vector(SIZE, args->w);

		print_max_number(SIZE, args);


		free(args->w);
		free(args->x);
		free(args);


	}
	else
	{
		printf("Usage: %s <num_inputs> <num_1> ... <num_n>\n", argv[0]);

		exit(-1);

	}

	return 0;
}