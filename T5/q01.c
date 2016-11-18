#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock; 

void method(int number);
void destroy(pthread_t* threads);
void* func(void* ptr);

int main(int argc, char** argv)
{

	const int number_of_threads = atoi(argv[1]);

	if(argc != 2 || number_of_threads > 10 || number_of_threads == 0)
	{
		printf("Usage: %s <number_of_threads>\n\n", argv[0]);
		printf("Ps: The number of threads must be grater than 1 and smaller than 10.\n");
		exit(1);
	}	
		




	pthread_t *threads;

	threads = (pthread_t *) calloc(number_of_threads, sizeof(pthread_t));


	for(int  i = 0; i < number_of_threads; ++i)
		threads[i] = pthread_create(&threads[i], NULL, &method, );



	method(number_of_threads);



	destroy(threads);

	return 0;
}


void destroy(pthread_t* threads)
{
	free(threads);
}

void method(int number)
{
	char aux = ' '; 

	for(int i = 96; i <= 96 + number; ++i)	
		aux =  i;

	for(int i = 0; i < number; ++i)
	{	
		if(i != number - 1)
			printf("%c ", aux);
		else
			printf("%c \n", aux);
	}
}