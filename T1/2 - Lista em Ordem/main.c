#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"
#include "sort.h"

int main(argc, char argv* [])
{
	initialize();

	if(argc == 1 || argc > 1 && argv [2] == "-d")
		increase_quick_sort(*vector, 0, vector_length - 1)
	
	else if((argc > 1 && argc < 3) && argv[2] == "-r")
		decrease_quick_sort(*vector, 0, vector_length - 1)

	else
		printf("Lembre-se somente é válido as flags: '-d' e '-r'. Sendo que elas 
				podem ser executas somente de forma individual\n");

	print_vector(&vector);

	destroy(&vector);

	return 0;	
}

