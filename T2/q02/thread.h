/*============================================================================*/
/*Name        : thread.h.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the headers to thread.c*/
/*============================================================================*/


typedef struct args
{
    int i_now;
    int j_now;
    int *w;
    int *x;
    int now;

}ARGS, *ptr_thread_arg;

int* initialize_vector_x(int size, char **input);

int* initialize_vector_w(int size);

void print_vector(int size, int *vector);

void destroy(int *v);

int* set_vector(int size, int *x);

void* set_one(void* args);

int* calculate_bigger(int size, ARGS *args);

void* compare_values(void* args);

void print_max_number(int size, ARGS *args);

void *show_max_number(void *args);



