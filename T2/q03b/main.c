/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#include <pthread.h>

#define max1i 3
#define max1j 2

#define max2i 2
#define max2j 3


typedef struct{
    int a00;
    int b00;
    int a01;
    int b10;
    int result;
}thread_arg, *ptr_thread_arg;

void *function_threads(void *arg){

    ptr_thread_arg arguments = (ptr_thread_arg)arg;

    arguments->result = arguments->a00 * arguments->b00 + arguments->a01 * arguments->b10;
    printf("Result: %d\n", arguments->result);
    printf("Calculus done!\n");
    return NULL;
}

int main()
{
    /*Declarations*/
    int matrix1[max1i][max1j] = {{1,2},
                                                      {4,3},
                                                      {5,5}};
    int matrix2[max2i][max2j] ={{2,2,4},
                                                     {4,1,0}};
    int result[3][3];

    pthread_t thread[9];

    thread_arg arguments;

    arguments.a00 = matrix1[0][0];
    arguments.b00 = matrix2[0][0];
    arguments.a01 = matrix1[0][1];
    arguments.b10 = matrix2[1][0];

    if(pthread_create(&(thread[0]), NULL,  function_threads, &arguments)){
        printf("Error to create Thread\n");
        return 1;
    }
    if(pthread_join(thread[0], NULL)) {
        printf("Error to joint Thread\n");
        return 2;
    }
    printf("Resultado 1: %d", arguments.result);

    printf("\n");

    return 0;
}
