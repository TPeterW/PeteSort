#include "Sort.h"
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

typedef int * List;

void Sort(int * numList, int length)
{
	int j;
	int upper = numList[0];
	int lower = numList[0];
	for(j = 0; j < length; j++)
	{
		if(numList[j] > upper)
			upper = numList[j];
		else if(numList[j] < lower)
			lower = numList[j];
	}
	
	int range = upper - lower + 1;
	
	// implementing this as a 2D-array
	List list = malloc(range * length * sizeof(int));
	int prev = lower - 1;
	int listCounter = 0;
		
	int x = 0, y = 0;
	// x ~ length, which is how many columns
	// y ~ range, which is how many rows
	for(x = 0; x < length; x++)
	{
		//printf("\nx = %d y = %d ", x, y);
		for(y = 0; y < range; y++)
			list[x * range + y] = lower - 1;
	}
	
	int i;
	for (i = 0; i < length; i++)
	{
		if (numList[i] > prev)	// if greater than the previous input, then stay in the same column
		{
			list[listCounter * range + numList[i] - lower] = numList[i];
		}
		else		// if smaller or equal to the previous input, then move to the next column
		{
			listCounter++;
			list[listCounter * range + numList[i] - lower]= numList[i];
		}
		prev = numList[i];                                                   // set the previous number as the most recent input
	}
	
	int counter = 0;
	for(y = 0; y < range; y++)
	{
		for(x = 0; x < length; x++)
		{
			if(list[x * range + y] != (lower - 1))
			{
				numList[counter]= list[x * range + y];	
				counter++;		
			}
		}
	}
	free(list);
}