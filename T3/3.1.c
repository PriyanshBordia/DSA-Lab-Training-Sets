#include "deque.h"

int main(int argc, char *argv[]) 
{
	int n = 0;
	printf("Enter Number: ");
	scanf("%d", n);
	joinL(n);

	printf("Enter Number: ");
	scanf("%d", n);
	joinL(n);

	printf("%d\n", size());
	printf("%d \n", leaveR());
	printf("%d\n", size());
	printf("%d \n", leaveR());
	printf("%d\n", size());	
	return 0;
} 
