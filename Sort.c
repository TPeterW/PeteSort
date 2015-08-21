#include "Sort.h"
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <stdint.h>

typedef int * List;

void PeterSort(int * numList, long long length, int lower, int upper)
{	
	int range = upper - lower + 1;
	
	// implementing this as a 2D-array
	List list = malloc(range * length * sizeof(int));
	int prev = lower - 1;
	long long listCounter = 0;
	
	long long x = 0, y = 0;
	// x ~ length, which is how many columns
	// y ~ range, which is how many rows
	for(x = 0; x < length; x++)
	{
		//printf("\nx = %d y = %d ", x, y);
		for(y = 0; y < range; y++)
			list[x * range + y] = lower - 1;
	}
	
	long long i;
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
	
	long long counter = 0;
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