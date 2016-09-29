/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#include <stdint.h>
#include <primo.h>

int main(void)
{

    long int primo;
    primo = gera_primo();
    printf("Numero primo: %ld\n", primo);

    return 0;
}
