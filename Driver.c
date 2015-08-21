#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "Sort.h"

#define SIZE 65536

int main(void)
{
	int input[SIZE];
	long long i = 0;
	long long j;
	double timeTaken;
	clock_t begin, end;
	
	// Read from stdin
//	printf("Please input 10 integer numbers: \n");
//	for(i = 0; i < SIZE; i++)
//	{
//		scanf("%d", &input[i]);
//	}
//	// Empty stdin
//	while(getchar() != '\n')
//		continue;
	
	// Read from file
	FILE * fp;
	fp = fopen("file1", "r");
	for(i = 0; i < SIZE; i++)
	{
		fscanf(fp, "%d", &input[i]);
	}
	
	int upper = input[0];
	int lower = input[0];
	for(j = 0; j < SIZE; j++)
	{
		if(input[j] > upper)
			upper = input[j];
		else if(input[j] < lower)
			lower = input[j];
	}
	
	begin = clock();
	
	PeterSort(input, SIZE, lower, upper);
	
	end = clock();
	
	timeTaken = (double)(end - begin) / CLOCKS_PER_SEC;
	
	
	
	for(i = 0; i < SIZE; i++)
	{
		printf("%d ", input[i]);
	}
	puts("");
	fclose(fp);
	
	printf("Time taken to perform the sort is %.2lf seconds\n", timeTaken);
	printf("And the clock ticked %ld times.\n", end - begin);
	
    system("pause");
	return 0;
}