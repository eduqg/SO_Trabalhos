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
	int *vector;
	int number_times;

	scanf("%d", &number_times);

	vector = initialize(vector, number_times);

	scan_vector(vector, number_times);	

	if(argc == 1 || (argc == 2 && !strcmp(argv[1], "-d")))
		increase_quick_sort(vector, 0, number_times - 1);
	
	else if(argc == 2 && !strcmp(argv[1], "-r"))
		decrease_quick_sort(vector, 0, number_times - 1);



	print_vector(vector, number_times);

	destroy(vector);

	return 0;
}
	