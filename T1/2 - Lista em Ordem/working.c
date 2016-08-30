#include <stdio.h>
#include <stdlib.h>
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

int* initialize(int *vector, int number)
{
	vector = (int*) calloc(number, sizeof(int));

	if(vector == NULL)
	{
		printf("Memória Insuficiente\n");
		exit(1);
	}	

	return vector;
}

void scan_vector(int *vector, int number)
{
	int i = 0;

	for(i = 0; i < number; ++i)
		scanf("%d", &vector[i]);
}

void print_vector(int *vector, int number)
{
	int i = 0;

	for(i = 0; i < number; ++i)
		printf("%d\n", vector[i]);
}

void destroy(int *vector)
{
	free(vector);
}

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
	