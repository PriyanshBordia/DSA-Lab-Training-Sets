#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	FILE *filePointer;
	char ch;

	filePointer = fopen("copy.c", "r");

	assert (filePointer != NULL);
	
	
	while ((ch = fgetc(filePointer)) != EOF)
	{
		printf("%c", ch);
	}

	fclose(filePointer);

	return 0;
}

	
