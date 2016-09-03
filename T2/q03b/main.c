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

    printf("Calculus done on Thread!\n");
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
    int i = 0;
    int j = 0;

    int a=0, b=0; /*to iterate four member per time on the matrix*/

    pthread_t thread[9];
    int n = 0; /*number of thread*/

    thread_arg arguments;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3 ; j++){
                arguments.a00 = matrix1[a][0]; /*00 00  |10 10 10 | 20 20 20*/
                arguments.b00 = matrix2[0][b]; /*01 02  |00 01 02 | 00 01 02*/
                arguments.a01 = matrix1[a][1]; /*01 01  |11 11 11 | 21 21 21*/
                arguments.b10 = matrix2[1][b]; /*11 12  |10 11 12 | 10 11 12*/
                if(pthread_create(&(thread[n]), NULL,  function_threads, &arguments)){
                    printf("Error to create Thread\n");
                    return 1;
                }
                if(pthread_join(thread[n], NULL)) {
                    printf("Error to joint Thread\n");
                    return 2;
                }
                result[i][j] = arguments.result;

                b++; n++;
        }
        a++; b = 0;
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3 ; j++){
            printf("[%d] ", result[i][j]);
        }
        printf("\n");
    }

    printf("Exiting...\n");

    return 0;
}
