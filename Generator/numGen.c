#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
	FILE * fp;
	fp = fopen("MostRecent", "w");
	time_t t;
	
	srand((unsigned) time(&t));
	int i;
	for(i = 0; i < 65536; i++)
	{

		int random = rand() % 1000;
		
		fprintf(fp, "%d ", random);
	}
	
	fclose(fp);
}