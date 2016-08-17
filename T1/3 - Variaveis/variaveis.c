#include <stdio.h>
#include "variaveis.h"


int main(){

	double number1 = 7.3, number2;
	char s1[100], s2[100];

	double *dPtr;
	dPtr = &number1;

	printf("Endereco de dPtr: %p\n", (void*)dPtr);
	printf("Valor apontado por dPtr: %.2f\n", *dPtr);

	number2 = *dPtr;
	printf("Valor em number2 atualizado: %.2f\n", number2);

	printf("Endereco de number 1: %s\n", &number1);


	return 0;
}
