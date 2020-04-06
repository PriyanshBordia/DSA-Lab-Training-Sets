#include "queue.h"

int main(void) 
{
	int i;
	init(); // Start deque
	
	for (i=0; i< 10; i++) 
	{
		printf("%d ", i);
		joinQ(i*i);
		printf("Size = %d Data = %d\n", size(), leaveQ());
		joinQ(i*i*i);	
	}
	
	while (size() > 0) 
	{
		printf("Emptying deque %d\n", leaveQ());
	}
		
	
	return 0;
}
