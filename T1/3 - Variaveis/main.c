#include <stdio.h>
#include "main.h"
#include <string.h>


int main(){

	double number1 = 7.3, number2;
	char s1[100], s2[100];

	float comparation = 0;
	int size_string_1 = 0;
	/*
	Declare a variável dPtr como ponteiro para a variável do tipo double.
	*/
	double *dPtr;
	/*
	Carregue o endereço da variável number1 no ponteiro dPtr .
	*/
	dPtr = &number1;
	/*
	Imprima em tela o valor da variável apontada por dPtr partindo do ponteiro.
	*/
	printf("Valor apontado por dPtr: %.2f\n", *dPtr);
	/*
	Carregue o valor da variável apontada por dPrt na variável number2 .
	*/
	number2 = *dPtr;
	/*
	Imprima o valor armazenado em number2.
	*/
	printf("Valor em number2 atualizado: %.2f\n", number2);
	/*
	Imprima o endereço de number1 na tela.
	*/
	printf("Endereco de number 1: %p\n", (void*)&number1);
	/*
	Imprima o endereço armazenado em dPtr na tela .
	*/
	printf("Endereco de dPtr: %p\n", (void*)dPtr);
	/*
	O valor impresso decorrente do enunciado que contempla o item anterior é igual ao
	valor do endereço gravado em dPrt?

	R: Sim, o valor é igual.
	*/

	/*
	Leia uma string e a armazene no array s1. Copie a string armazenada em s1 para
	s2. Compare a string armazenada em s1 com a string armazenada em s2 e imprima
	o resultado na tela.
	*/
	printf("Digite uma string: ");
	scanf("%s", s1);
	strcpy(s2,s1);
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

	comparation = strcmp(s1,s2);
	if(comparation == 0)
	{
		printf("As strings são iguais\n");
	}
	else
	{
		printf("As strings são diferentes\n");
	}

	/*
	Apense a string s2 à string s1. Imprima o resultado na tela.
	Apensar: Juntar
	*/

	strcat(s2,s1);
	printf("s2: %s\n", s2);

	/*
	A execução do item anterior pode provocar algum erro em tempo de execução?

	R: Pode, se a junção das duas strings superar o valor alocado de s2.
	*/
	/*
	Determine o comprimento da string armazenada em s1 e imprima o resultado na
	tela.
	*/
	size_string_1 = strlen(s1);
	printf("O tamanho da string 1 é: %d\n", size_string_1);

	return 0;
}
