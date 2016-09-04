#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct vector VECTOR;

struct vector
{
	int vector_size;
	int *vector;
};

VECTOR* initialize(VECTOR* vector, int size)
{
	vector = (VECTOR*) calloc(1, sizeof(VECTOR));
	vector -> vector = (int*) calloc(size, sizeof(int));
	vector -> vector_size = size;
	return vector;
}


//Creating thread1

void* vector_set(void*  arg)
{
	VECTOR *temp = (VECTOR*) arg;
	
	for(int i = 0; i < temp -> vector_size; ++i)
		temp -> vector[i] = 1;

}


void print_vector(int *vector, int size)
{
	for(int i = 0; i < size; ++i)
		printf("%d ", vector[i]);

	printf("\n");
}


int main(int argc, char* argv[])
{
	VECTOR *vector;

	//pthread_t t1;

	const int SIZE = atoi(argv[1]);;

	vector = initialize(vector, SIZE);

	vector_set((void*) vector);

	print_vector(&vector.vector, SIZE);


	//pthread_create(&t1, NULL, vector_set, (void*) vector);

	// pthread_join_t(t1, NULL);



	exit(0);
}