/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#include <stdint.h>

int testa_primo(int32_t primo);
int32_t gera_primo();


int main(void)
{

    long int primo;
    primo = gera_primo();
    printf("Numero primo: %ld\n", primo);

    return 0;
}
