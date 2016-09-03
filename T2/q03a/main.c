/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#define max1i 3
#define max1j 3

#define max2i 3
#define max2j 2

int main()
{
    /*Declarations*/
    int matrix1[max1i][max1j] = { {1,2,0},
                                                       {4,3,1},
                                                        {5,5,5}};
    int matrix2[max2i][max2j] ={ {2,2},
                                                       {4,4},
                                                       {1,4}};
    int result[100][100];

    int i = 0;
    int j = 0;
    int k = 0;
    int sum = 0;

    /* Verify condition to multiply*/
    if(max1j == max2i){
        printf("É possível multiplicar essa matriz\n");
    }else{
        printf("É impossível multiplicar essa matriz\n");
        return(0);
    }


    /*Set all values of the result matrix to 0*/
    for(i = 0; i < max1i ; i++){
        for(j = 0; j < max1j; j++){
            result[i][j] = 0;
        }
    }

    /*Do all calculus for the multiplication of the matrix*/
    for(i = 0; i < max1i ; i++){
        for(j = 0; j < max2j; j++){
            sum= 0;
            for(k = 0; k < max1j ; k++){
                sum+= matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    /*print the result*/
    printf("Matriz do Resultado:\n");
    for(i = 0; i < max1i; i++){
        printf("\n");
        for( j = 0; j < max2j; j++){
            printf("[%d][%d]: %d ", i, j, result[i][j]);
        }
    }
    printf("\n");

    return 0;
}
