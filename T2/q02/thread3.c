#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct args ARGS;

struct args
{
	int i;
	int j;
	int *x;
	int *w;
	int i_value;
	int j_value;
};

void* set_one(void* args)
{
	int *temp  = args;
	*temp = 1;

	pthread_exit(0);
}

void* compare_values(void* args)
{
	ARGS *aux = (ARGS *) args;

	if((aux -> w[aux -> i]) < (aux -> w[ aux -> j]))
	{
		aux -> i = aux -> i;
		aux -> j = aux -> j;
		aux -> i_value = aux -> w[aux -> i];
		aux -> j_value = aux -> w[aux -> j];		
		aux -> w[aux -> i] = 0; 		
	}
	else
	{
		aux -> i = aux -> i;
		aux -> j = aux -> j;
		aux -> i_value = aux -> w [aux -> i];
		aux -> j_value = aux -> w [aux -> j];		
		aux -> w[aux -> j] = 0; 	
	}

	
	pthread_exit(0);
}


int* calculate_bigger(int length, ARGS *arg)
{
	int m = 0;

 
	pthread_t *threads;

	m = length * (length -1)/2;
	threads = (pthread_t *) calloc(m, sizeof(pthread_t));

	for(int i = 0; i < m; ++i)
		for(int j = i + 1; i < m; ++j)
			pthread_create(&threads[i], NULL, &compare_values, &arg);


	for(int i = 0; i < m; ++i)
		for(int j = i + 1; i < m; ++j)
			pthread_join(threads[i], NULL);




	free(threads);

	return arg -> w;
}

int* set_vector(int length, int **x)
{
	int *w = (int *) calloc(length, sizeof(int));
	pthread_t *threads;

	w = &(**x);
	
	threads = (pthread_t *) calloc(length, sizeof(pthread_t));

	for(int i = 0; i < length; ++i)
		pthread_create(&threads[i], NULL, &set_one, &w[i]);

	for(int i = 0; i < length; ++i)
		pthread_join(threads[i], NULL);

	free(threads);


	return w;

} 

int main(int argc, char **argv)
{

	if(argc <  2)
	{
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
	}
	else
	{		
		ARGS *arg;
		const int SIZE = atoi(argv[1]);

		if(SIZE > 100)
		{
			printf("Aceita-se apenas 100 valores\n");
			exit(0);
		}

		arg = (ARGS *) calloc(SIZE, sizeof(ARGS));
		arg -> w = (int *) calloc(SIZE, sizeof(int));
		arg -> x = (int *) calloc(SIZE, sizeof(int));


		

		for(int i = 2; i < (SIZE + 2); ++i)
			arg -> x[(i - 2)] = atoi(argv[i]);

		printf("Entradas\n");

		for(int i = 2; i < SIZE + 2; ++i)		
			printf("%d ", arg -> x[i - 2]);

		arg -> w = set_vector(SIZE, &(arg -> x));


		printf("\nVetor Setado com 1\n");

		for(int i = 2; i < SIZE + 2; ++i)		
			printf("%d ", arg -> w[i - 2]);

		arg -> w = calculate_bigger(SIZE, arg);

		int m = SIZE * (SIZE -1)/2;

		printf("\nVetor depois da THREAD\n");

		for(int i = 0; i < m ; ++i )
			printf("%d ", arg -> w[i - 2]);
		

		printf("\n");


	}


	exit(0);
}
