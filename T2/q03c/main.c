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
#include <stdlib.h>

#define max1i 3
#define max1j 2

#define max2i 2
#define max2j 3

typedef struct
{
    int a00;
    int b00;
    int a01;
    int b10;
    int result;
}thread_arg, *ptr_thread_arg;

void *function_threads(void *arg)
{
    /*Cast to be able to use varibles */
    ptr_thread_arg arguments = (ptr_thread_arg)arg;

    /*Calculus to one cel of result matrix: a00 * b00 + a01 * b10*/
    arguments->result = arguments->a00 * arguments->b00 + arguments->a01 * arguments->b10;

    printf("Calculus done on Thread!\n");

    return NULL;
}

int main()
{

    pthread_t *thread;

    thread_arg *argument;

    /*number of thread*/
    int n = 0, num = 0;

    int matrix1[max1i][max1j] = {{-2, 3},
                                                      {-4,-2},
                                                      { 5, 1}};
    int matrix2[max2i][max2j] ={{ 4, 1, 3},
                                                     { 2,-5, 7}};
    int result[3][3];

    /*to iterate four member per time on the matrix*/
    int a = 0, b = 0;

    int i = 0, j = 0;

    double startTime = 0;
    double endTime = 0;
    double timeElapsed = 0;

    startTime = (float)clock()/CLOCKS_PER_SEC;

    thread = (pthread_t*)malloc(2 * sizeof(pthread_t));
    argument = (thread_arg*)malloc(9 * sizeof(thread_arg));

    /*This entire for uses a and b to iterate all values to multiply the matrix1 and matrix2*/
    /*For example: Two matrix 2x2: */
    /*A = [a00][a01]  B = [b00][b01]*/
    /*       [a10][a11]         [b10][b11]*/
    /*To have the first cel of one matrix result, we have to calculate a00 * b00 + a01 * b10 */
    /* Using this logic we can use for all cels of any matrix in this code */

    for(i = 0; i < max1i  ; i++)
    {
        for(j = 0; j < max2j  ; j++)
        {
            argument[n].a00 = matrix1[a][0];
            argument[n].b00 = matrix2[0][b];
            argument[n].a01 = matrix1[a][1];
            argument[n].b10 = matrix2[1][b];

            b++; n++;
        }
        a++; b = 0;
    }

    /*Package 1*/
    pthread_create(&thread[0], NULL,  function_threads, (void*)&argument[0]);
    pthread_create(&thread[1], NULL,  function_threads, (void*)&argument[1]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    /*Package 2*/
    pthread_create(&thread[0], NULL,  function_threads, (void*)&argument[2]);
    pthread_create(&thread[1], NULL,  function_threads, (void*)&argument[3]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    /*Package 3*/
    pthread_create(&thread[0], NULL,  function_threads, (void*)&argument[4]);
    pthread_create(&thread[1], NULL,  function_threads, (void*)&argument[5]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    /*Package 4*/
    pthread_create(&thread[0], NULL,  function_threads, (void*)&argument[6]);
    pthread_create(&thread[1], NULL,  function_threads, (void*)&argument[7]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    /*Package 5*/
    pthread_create(&thread[0], NULL,  function_threads, (void*)&argument[8]);
    pthread_join(thread[0], NULL);

    printf("\n");
    for(i = 0; i < 3 ; i++)
    {
        for(j = 0; j < 3  ; j++)
        {
            result[i][j] = argument[num].result;
            printf("[%d] ", result[i][j]);
            num++;
        }
        printf("\n");
    }

    free(thread);
    free(argument);

    endTime = (float)clock()/CLOCKS_PER_SEC;
    timeElapsed = endTime - startTime;

    printf("\nTempo de Execucao: %.6f\n", timeElapsed);

    return 0;
}
