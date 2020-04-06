// FUNCTON DEFINATIONS

#include "queue.h"
#include "deque.h"

void joinQ(int val)
{
	insertRight(val);
}

int leaveQ()
{
	return removeLeft();
}

void fill()
{
	int d = 2;
	while (d < SIZE)
	{
		joinQ(d);
		d++;
	}
}

void primes()
{
	printf("_______\n");
	printf("Primes: ");
	while (size() != 0)
	{
		int prime = leaveQ();

		if (pow(prime, 2) > SIZE)
			break;

		else
		{
			printf("%d ", prime);
			check(prime);
		}
	}

	display();
	printf("\n_______\n");
}

int isdivi(int x, int y)
{
	if (x % y == 0)
		return 1;
	else
		return 0;
}

void loop(int prime)
{	
	int x = leaveQ();
		
	if (x != ERR_DATA)
	{
		if (!isdivi(x, prime))
		{
			joinQ(x);
		}
	}
}

void check(int prime)
{
	int temprgt = (vright()+ 1) % SIZE; 

	while (vleft() != temprgt)
	{
		loop(prime);	
	}
}

void display()
{
	while (size() != 0)
		printf("%d ", leaveQ());
}

