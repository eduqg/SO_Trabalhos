#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int* initialize_vector(int size, char **input)
{
	int *x = (int *) calloc(size, sizeof(int));

	for(int i = 2; i < size + 2; ++i)
		x[i - 2] = atoi(input[i]);

	return x;
}

void print_vector(int size, int *vector)
{
	for(int  i = 0; i < size; ++ i)
		printf("%d ", vector[i]);

	printf("\n");
	
}

void destroy(int *vector)
{
	free(vector);
}

void* set_one(void *args)
{
	int *w = args;
	*w = 1;

	pthread_exit(0);
}

int* set_vector(int size, int *x)
{
	int *w = x;
	pthread_t *threads;

	threads = (pthread_t *) calloc(size, sizeof(pthread_t));

	for(int  i = 0; i < size; ++i)
		pthread_create(&threads[i], NULL, &set_one, (void *) &w[i]);

	for(int  i = 0; i < size; ++i)
		pthread_join(threads[i], NULL);

	free(threads);

	return w;
}