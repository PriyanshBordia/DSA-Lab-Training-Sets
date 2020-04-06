#include "deque.h"

int main()
{
	push('#');

	FILE *filePointer;
	char ch;

	filePointer = fopen("copy.c", "r");

	assert (filePointer != NULL);
	/*{
		printf("File unavailable!!");
		exit(0);
	}*/

	{
		while ((ch = fgetc(filePointer)) != EOF)
		{
			if (ch == '(' || ch == '{' || ch == '[')
			{
				push(ch);
				printf("\n");
			}
			else if (ch == ')' && (!isEmpty()))
			{
				char c = pop();
				assert (c == '(');
				printf("\n");
			}

			else if (ch == '}' && (!isEmpty()))
			{
				char c = pop();
				assert (c == '{');
				printf("\n");
			}

			else if (ch == ']' && !isEmpty())
			{
				char c = pop();
				assert (c == '[');
				printf("\n");
			}

		}
	}

	fclose(filePointer);

	char c = pop();
	assert(c == '#');

	return 0;
}

	
