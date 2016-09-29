/*============================================================================*/
/*Name        : primo.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains functions*/
/*============================================================================*/


#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "primo.h"

int32_t gera_primo(){
    int32_t random;

    srand((unsigned) time(NULL));
    do{
        random = rand();
    } while(!testa_primo(random));
    return random;
}

int testa_primo(int32_t numero){

    int32_t  limite = sqrt(numero) + 1;
    int32_t i;

    /*Referencia http://br.ccm.net/faq/10300-verificar-se-um-inteiro-e-um-numero-primo-em-c*/
    if (numero % 2 == 0)
    {
        return 0;

    }
    else
    {
        for (i = 3; i < limite; i += 2)
        {
            if (numero % i == 0)
            {
                return 0;
            }
        }
    }

    return 1;

}
