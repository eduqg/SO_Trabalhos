/*
 ============================================================================
 Name        : sort.c
 Author      : Eduardo Gomes and Miguel Pimentel
 Version     :
 Copyright   :
 Description : Ordenate a dynamic vector of integer
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"
#include "sort.h"

int main(int argc, char* argv[])
{
	int *vector = NULL;
	int number_times = 0;

	if(argc == 1 || (argc == 2 && !strcmp(argv[1], "-d")))
	{
		printf("Insira a quatidade de valores que deseja ordenar: ");
		scanf("%d", &number_times);
		vector = initialize(vector, number_times);	
		scan_vector(vector, number_times);	
		printf("\n********** Valores em Ordem Crescente **************\n");
		increase_quick_sort(vector, 0, number_times - 1);
		print_vector(vector, number_times);
		destroy(vector);
	}	
	else if(argc == 2 && !strcmp(argv[1], "-r"))
	{
		printf("Insira a quatidade de valores que deseja ordenar: ");
		scanf("%d", &number_times);
		vector = initialize(vector, number_times);
		scan_vector(vector, number_times);	
		printf("\n********** Valores em Ordem Decrescente *************\n");
		decrease_quick_sort(vector, 0, number_times - 1);
		print_vector(vector, number_times);
		destroy(vector);
	}
	else
	{
		printf("Somente é aceito os parâmetros '-d' e '-r . Tente novamente!\n");
	}
	

	return 0;
}
	