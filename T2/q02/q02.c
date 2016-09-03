#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <pthread.h>

//Thread functiion to compare values
void* compare_values(void *arg)
{
	long long limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;

	//To do: what to do with answer 
}

int* initialize(int* vector, int vector_size)
{
	vector = (int*) calloc(vector_size, sizeof(int));
	return vector;
}

void set_vector(int* vector, int vector_size, int value)
{	
	for(int i = 0; i < vector_size; ++i)
		vector[i] = value;
}

void print_vector(int* vector, int vector_size)
{
	for(int i = 0; i < vector_size; ++i)
		printf("%d ", vector[i]);

	printf("\n");
}

int main(int argc, char* argv[])
{
	int *vector = NULL;

	if(argc < 2)
	{
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
	}

	vector = initialize(vector, argc);

	//Thread ID
	pthread_t tid;

	//Create attributes
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, compare_values, &limit);

	print_vector(vector,argc);

	set_vector(vector, argc, 1);

	print_vector(vector,argc);



	return 0;
}
