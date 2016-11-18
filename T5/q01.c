#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock; 
pthread_t* threads;

int isOK = 1;

int number_of_threads = 0;

void destroy(pthread_t* threads);
void* function(void *ptr);

int main(int argc, char** argv)
{
	number_of_threads = atoi(argv[1]);

	if(argc != 2 || number_of_threads > 10 || number_of_threads == 0)
	{
		printf("Usage: %s <number_of_threads>\n\n", argv[0]);
		printf("Ps: The number of threads must be grater than 0 and smaller than or equal to 	10.\n");
		exit(1);
	}	
	else
		//NOTHING TO DO

	//Handler to control when to operation should stop
	//signal(SIGINT, handler);
	
	threads = (pthread_t *) calloc(number_of_threads, sizeof(pthread_t));

	int max_number_of_inputs[10];

	for(int i = 1; i < 10 ; ++i)
		max_number_of_inputs[i] = i;

	for(int i = 0; i < number_of_threads; ++i)
		pthread_create(&threads[i], NULL, function, &max_number_of_inputs[i]);


	while(isOK);


	destroy(threads);

	return 0;
}


void destroy(pthread_t* threads)
{
	free(threads);
}


void* function(void *ptr)
{
	int *index = (int *) ptr;
	
	while(isOK)
	{
		//Similar to Sleep. The params are in microsecond	
	 	usleep(500000);

	 	//Lock a thread using a mutex
	 	pthread_mutex_lock(&lock);

	 	//Print acord to ascci table
	 	for(int i = 97; i <= *index + 97; ++i)
	 		printf("%c ", i);

	 	printf("\n");

 		//Unlock a thread using a mutex
	 	pthread_mutex_unlock(&lock);
	}

 	//Function that terminates the calling thread
	pthread_exit(0);
}

