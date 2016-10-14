/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>

int main(void)
{

	char time[12] = {'2','0','1','6','0','2','1','2','0','9','0','0'};
	int i = 0;

	/*
	do{
		printf("Escreva a data no formato AAAAMMDDHHmm:\n");
		scanf("%s", time);
	}while((tam = strlen(time))!=12);

	*/

	for(i = 0; i < 12; i++){
		printf("%c\n", time[i]);
	}



		
	return 0;
}
