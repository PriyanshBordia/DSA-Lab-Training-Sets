/* An implementation of Deque  */

#include <stdio.h>
#include "deque.h"

int data[SIZE];
int left = SIZE - 1;
int right = SIZE;

int insertLeft(int d) 
{
	if (size() == SIZE - 1)
	{
		printf("No more Space!!");
		return 0;
	}

	else					
    {
    	data[left] = d;									
    	left = (left + 1) % SIZE;
    	return 1;
	}								
}

int insertRight(int d) 
{
	if (size() == SIZE - 1)
	{
		printf("No more Space!!\n");
		return 0;
	}

	else
	{	
		data[right] = d;
		right = (right - 1 + SIZE) % SIZE;
		return 1;
	}
}

int removeLeft() 
{
	int d, s;
	
	s = size();
	
	if (s == 0)
		return ERR_DATA; // Error value
	
	left = (left - 1 + SIZE)%SIZE;

	d = data[left];
	
	if (s == 1) 
		init();
	
	return d;
}

int removeRight() 
{
	int d, s;
	
	s = size();
	
	if (s == 0)
		return ERR_DATA; // Error value

	right = (right + 1)%SIZE;

	d = data[right];
	
	if (s == 1) 
		init();

	return d;
}

int hasWelcome() 
{
	return size() < SIZE;
}

int isEmpty() 
{
	if (size() == 0)
		return 1;
	else
		return 0;
}

void init() 
{
	right = SIZE - 1;
	left = 0;
}

int size() 
{
	return (left - 1 - right + SIZE) % SIZE;
}

int vright()
{
	return right;
}

int vleft()
{
	return left;
}