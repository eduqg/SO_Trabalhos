#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void increase_quick_sort(int *vector, int left_element , int right_element)
{
	
	int pivot_element = left_element, i, current_element ,j;
 	
	for(i = left_element + 1; i <= right_element; ++i)
	{
		j = i;
        	if(vector[j] < vector[pivot_element])
		{
         		current_element = vector[j];

         		while(j > pivot_element)
			{    
          			  vector[j] = vector[j-1];
			            j--;
         		}

         		vector[j] = current_element;
         		pivot_element++;        
        	}  
	}
    
	if(pivot_element - 1 >= left_element)
	{
	        increase_quick_sort(vector , left_element , pivot_element - 1);
	}

    	if(pivot_element +1 <= right_element)
	{
	        increase_quick_sort(vector , pivot_element + 1, right_element);
	}
}

void decrease_quick_sort(int *vector, int left_element , int right_element)
{
	
	int pivot_element = left_element, i, current_element ,j;
 	
	for(i = left_element + 1; i <= right_element; ++i)
	{
		j = i;
        	if(vector[j] > vector[pivot_element])
		{
         		current_element = vector[j];

         		while(j > pivot_element)
			{    
          			  vector[j] = vector[j-1];
			            j--;
         		}

         		vector[j] = current_element;
         		pivot_element++;        
        	}  
	}
    
	if(pivot_element - 1 >= left_element)
	{
	        decrease_quick_sort(vector , left_element , pivot_element - 1);
	}

    	if(pivot_element +1 <= right_element)
	{
	        decrease_quick_sort(vector , pivot_element + 1, right_element);
	}
}

int main(int argc, char* argv[])
{
	int* vector;
	int number_times;
	int counter  = 0;
	int option;

	scanf("%d", &number_times);


	vector = (int*) calloc(number_times, sizeof(int));


	for(counter = 0; counter < number_times; ++counter)
		scanf("%d", &vector[counter]);

	//printf("Para ordenação crescente aperte 1, para operação decrescente aperte 0: ");

	//scanf("%d", &option);

	//if(option == 1)
		//increase_quick_sort(vector, 0, number_times - 1);

	//else if(option == 0)
		//decrease_quick_sort(vector, 0, number_times - 1);
	printf("%s\n", argv[1]);

	if(argc == 1)
	{	
		increase_quick_sort(vector, 0, number_times - 1);
		printf("cresceu\n");
	}
	else if(argc == 2 && !strcmp(argv[1], "-d"))
	{
		increase_quick_sort(vector, 0, number_times - 1);
		printf("mais ou menos\n");
	}
	else if(argc == 2 && !strcmp(argv[1], "-r"))
	{
		decrease_quick_sort(vector, 0, number_times - 1);
		printf("decresceu\n");
	}	


	for(counter = 0; counter < number_times; ++counter)
		printf("%d\n", vector[counter]);

	free(vector);

	return 0;
}
	