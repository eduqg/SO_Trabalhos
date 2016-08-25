#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{


	if(argc == 2 &&  strcmp(argv[1], "miguel") == 0)
		printf("Uma entrada\n");

	else if(argc == 2)
		printf("Duas entrada\n");

	else
		printf("Diferente das entradas tradicionais\n");


	return 0;
}