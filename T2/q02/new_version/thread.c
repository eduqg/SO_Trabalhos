#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "thread.h"


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

int* calculate_bigger(int size, ARGS *args)
{
	int *w = args -> w;
	pthread_t *threads;

	int  m = size* (size - 1) / 2;

	threads = (pthread_t *) calloc(m, sizeof(pthread_t));

	for(int i = 0; i < size; ++i)
	{
		for(int j = i + 1; i < size; ++i)
		{
			int counter = 0;
			args[counter].i = i;
			args[counter].j = j;
			args[counter].i_value = w[i];
			args[counter].j_value = w[j];
			pthread_create(&threads[i], NULL, &compare_values, &w[i]);
			++counter;
		}
	}


	for(int  i = 0; i <m; ++i)
		for(int  j = i + 1; i < m; ++j)
			pthread_join(threads[i], NULL);

	free(threads);

	return w;

}

void* compare_values(void* args)
{
	ARGS *aux = (ARGS *) args;

	int i =  aux -> i;
	int j =  aux -> j;
	

	if(i < j)
		aux -> w[i] = 0;

	else
		aux -> w[j] = 0;

	pthread_exit(0);

}
