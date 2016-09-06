#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct vector VECTOR;

struct vector
{
	int position_value; // Values provided for function: set_vector
	int  value; // Values provided for user inputs
	int length;
};

void* compare(void *arg)
{

}

void* set_vector(void *arg)
{
	VECTOR *aux = (VECTOR *)(arg);
	aux -> position_value = 1;
}

VECTOR* initialize(int size)
{

	VECTOR *aux = NULL;
	aux = (VECTOR* ) calloc(1, sizeof(VECTOR));
	aux -> length = size;
	return aux;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
	}	
	else
	{
		VECTOR *w;
		const int SIZE = atoi(argv[1]);
		pthread_t *threads;

		threads = (pthread_t *) calloc(SIZE, sizeof(pthread_t));

		//Alocating memory for a vector struct
		for(int i = 0; i < SIZE; ++i)
			w = initialize(SIZE);

		///*Testing value allocated */printf("%ld \n\n\n\n", sizeof(v[3]));

		//Printing values of each allocated struct 
		for(int i = 0; i < SIZE; ++i)
			printf("%ld  %d       %d\n", sizeof(w[i]), i, w[i].length);
	
		//Creating thread to set a vector
		for(int i = 0; i < SIZE; ++i)
			pthread_t_create(&thread[i], NULL, set_vector, (void*) &w[i]);
	

	}	

	return 0;
}