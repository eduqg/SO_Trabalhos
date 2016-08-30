#include <stdio.h>
#include <stdlib.h>

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