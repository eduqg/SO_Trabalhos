#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef args ARGS;

struct args
{
	int i;
	int i_value;
	int j_value;
	int j;
	int *w;
	int *x;
}

print_vector()

void* set_one(void*  args)
{
	int temp* = args;
	args = 1;
}
 
int* set_vector(int size, int* x)
{
	int *w = x;
	pthread_t  *threads;

	threads = (pthread_t *) calloc(size, sizeof(pthread_t));
	
	for(int i  = 0; i < size; ++i)
		pthread_create(&threads[i], NULL, &set_one, &(void *) w[i]);

	for(int i = 0; i < size; ++i)
		pthread_join(w[i], NULL);

	return w;

	free(threads);
}

int* initialize_vector(int size, char **argv)
{
	int *x = (int *) calloc(size, sizeof(int));

	for(int  i = 2; i < size + 2; ++i)
		x[i - 2] = atoi(argv[i]);

	return x;

	free(x);
}

int main(int argc, char **argv)
{
	if(argc > 2)
	{
		ARGS *args;
		const int SIZE = atoi(argv[1]);

		args -> x =  initialize_vector(SIZE, *argv);
		arg -> w = set_vector(SIZE, args -> x);



	}
	else
	{
		printf("Usage: %s <number_of_times> <number_1> ... <number_n>\n", argv[0]);
		exit(-1);
	}


	exit(0);
}