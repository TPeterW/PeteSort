#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "Sort.h"

#define SIZE 5000

int main(void)
{
	int input[SIZE];
	int i = 0;
	
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
	
	
	Sort(input, SIZE);
	
	for(i = 0; i < SIZE; i++)
	{
		printf("%d ", input[i]);
	}
	puts("");
	fclose(fp);
	//system("pause");
	return 0;
}