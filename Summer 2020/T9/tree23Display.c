#include "tree23.h"

static void display2(node23p node, int offset);
static void printSpaces(int offset);

void display() 
{
	if (toRoot == NULL) 
	{
		printf("NULL TREE\n");
		return; 
	}
	
	display2(toRoot, 0);
}

	   
static void printSpaces(int offset) 
{
	for (int i = 0; i < offset; i++) 
		printf(" ");
}

void display2(node23p node, int offset) 
{	
	if (node == NULL) 
	{ 
		printSpaces(offset);
	    printf("{ NULL }\n");
		return; 
	}

	printSpaces(offset);
	
	printf("{ count of keys = %d\n", node->countKeys); 

	for (int kys = 0; kys <= node->countKeys; kys++)
		switch(kys) 
		{
			case 0:
				printSpaces(offset);
				printf(" <%d\n", node->data[0]); 
				display2(node->subT[0], offset+5); 
				break;
			
			case 1:
				if (kys < node->countKeys) 
				{
					printSpaces(offset);
					printf(" <%d && >%d\n", node->data[1], node->data[0]); 
					display2(node->subT[1], offset+5);
					break;
				} 

				else 
				{
					printSpaces(offset);
					printf(" >%d\n", node->data[0]); 
					display2(node->subT[1], offset+5); 
					break;
	   			}

			case 2:
				printSpaces(offset);
				printf(" >%d\n", node->data[1]); 
				display2(node->subT[2], offset+5); 
				break;
		}

		printSpaces(offset);
		printf("}\n");
}
