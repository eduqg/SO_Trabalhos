#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "thread.h"


int* initialize_vector_x(int size, char **input)
{
	int *x = (int *) calloc(size, sizeof(int));

	for(int i = 2; i < size + 2; ++i)
		x[i - 2] = atoi(input[i]);

	return x;
}

int* initialize_vector_w(int size)
{
	int *w = (int*) calloc(size, sizeof(int));
	pthread_t thread[size];
	int n = 0;
	for(n = 0; n < size; n++)
		pthread_create(&thread[n], NULL,  set_one, (void*)&w[n]);

	for(n = 0; n < size; n++)
		pthread_join(thread[n], NULL);

	return w;
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
	printf("No bigger\n");

	int i = 0, j = 0;

	int  m = size* (size - 1) / 2.0;

	ARGS *args1 = (ARGS *) malloc(m*sizeof(ARGS));
	//args1 -> now = (int*)malloc(m)
	pthread_t *thread;

	thread = (pthread_t*)malloc(m * sizeof(pthread_t));

	int n = 0;

   	for(i = 0; i < size; ++i){
		for(j = i + 1; j < size; ++j, n++){
			args1[n].x = args -> x;
			args1[n].i_now = i;
			args1[n].w = args ->w;
			args1[n].j_now = j;

		}
    	}
    	//printf("---X\n"); print_vector(size,args1->x);
	for(n=0; n < m; n++){
		pthread_create(&thread[n], NULL, compare_values, (void*)&args1[n]);
    	}



    	for(i = 0; i < n; ++i)
	{

		printf("\nThread %d Voltando\n",i);
		void *result;
		pthread_join(thread[i], &result);

		int result_is = *((int*)result);
		printf("Result_is: %d\n", result_is);
		if(result_is == -1)
			continue;

		args1 -> w[result_is] = 0;
		print_vector(size, args1->w);

    	}
    	printf("Size: %d\n", size);


    	free(thread);
	return args->w;

}
void* compare_values(void* arguments)
{
	ARGS *args1 = (ARGS*)arguments;

	int i_now = args1->i_now;
	int j_now = args1 -> j_now;

	int first = args1->x[i_now];
	int second = args1->x[j_now];

	//printf("-------i_now->: %d j_now-> %d\n", i_now,j_now);
	if(first < second){
		//printf("Second %d é maior que %d\n",second, first );
		pthread_exit(&args1->i_now);
	}
	if(first > second){
		//printf("First %d é maior que %d\n",first,second);
		pthread_exit(&args1->j_now);
	}
	else
	{
		args1->i_now = -1;
		pthread_exit(&args1->i_now);
	}

	//printf("Thread to Compare Values Done!\n");

	return NULL;
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
	printf("Thread set to 1 Done!\n");
	int *w = args;
	*w = 1;

	return NULL;
}

