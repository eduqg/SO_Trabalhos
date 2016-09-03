/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#include <pthread.h>
#include <time.h>

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
    int matrix1[max1i][max1j] = {{-2,3},
                                                      {-4,-2},
                                                      {5,1}};
    int matrix2[max2i][max2j] ={{4,1,3},
                                                     {2,-5,7}};

    int i = 0;
    int j = 0;

    int result[3][3];

    int a=0, b=0; /*to iterate four member per time on the matrix*/

    pthread_t thread[2];
    int z = 0;

    thread_arg arguments;

    double startTime = 0;
    double endTime = 0;
    double timeElapsed = 0;

    startTime = (float)clock()/CLOCKS_PER_SEC;

    for(i = 0; i < max1i; i++){
        for(j = 0; j < max2j ; j++){
                /*set all values of the matrix*/
                arguments.a00 = matrix1[a][0]; /*00 00  |10 10 10 | 20 20 20*/
                arguments.b00 = matrix2[0][b]; /*01 02  |00 01 02 | 00 01 02*/
                arguments.a01 = matrix1[a][1]; /*01 01  |11 11 11 | 21 21 21*/
                arguments.b10 = matrix2[1][b]; /*11 12  |10 11 12 | 10 11 12*/
                if(pthread_create(&(thread[z]), NULL,  function_threads, &arguments)){
                    printf("Error to create Thread\n");
                    return 1;
                }
                if(pthread_join(thread[z], NULL)) {
                    printf("Error to joint Thread\n");
                    return 2;
                }
                result[i][j] = arguments.result;

                b++;

                if(z == 0){
                    z=1;
                }else{
                    z=0;
                }
        }
        a++; b = 0;
    }

    printf("Matriz do Resultado:\n");
    for(i = 0; i < max1i; i++){
        printf("\n");
        for( j = 0; j < max2j; j++){
            printf("[%d][%d]: %d ", i, j, result[i][j]);
        }
    }

    endTime = (float)clock()/CLOCKS_PER_SEC;
    timeElapsed = endTime - startTime;

    printf("\n\nTempo de Execucao: %.6f\n", timeElapsed);

    return 0;
}