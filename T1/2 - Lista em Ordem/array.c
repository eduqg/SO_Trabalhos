#include <stdio.h>
#include <stdlib.h>


int* initialize(int *vector, int number)
{
	vector = (int*) calloc(number, sizeof(int));

	if(vector == NULL)
	{
		printf("Memória Insuficiente\n");
		exit(1);
	}	

	return vector;
}

void scan_vector(int *vector, int number)
{
	int i = 0;

	for(i = 0; i < number; ++i)
		scanf("%d", &vector[i]);
}

void print_vector(int *vector, int number)
{
	int i = 0;

	printf("\n");
	for(i = 0; i < number; ++i)
		printf("%d\n", vector[i]);
}

void destroy(int *vector)
{
	free(vector);
}
