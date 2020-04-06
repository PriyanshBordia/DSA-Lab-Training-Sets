/* An implementation of Deque  */

#include "deque.h"

int data[SIZE];
int left = -1;
int right = -1;

int insertLeft(int d) 
{
	if (size() == SIZE - 1)
		return 0;

	if (left == -1) 
	{
		left=right=0;
		data[left]= d;
		return 1;
	}

	else									// inserting twice for left = -1
    {									//
    	left = (left - 1 + SIZE) % SIZE;
	    data[left] = d;
	    return 1;
	}								
}

int insertRight(int d) 
{
	if (size() == SIZE - 1)
		return 0;

	if (right == -1)
	{
		left = right = 0;
		data[right] = d;
		return 1;
	}

	else
	{	
		right = (right + 1) % SIZE;
		data[right] = d;
		return 1;
	}
}

int removeLeft() 
{
	int d, s;
	
	s = size();
	
	if (s == 0)
		return ERR_DATA; // Error value

	d = data[left];
	
	left = (left + 1)%SIZE;
	
	if (s == 1) 
		init();
	
	return d;

	// return 0; // Not implemented
}

int removeRight() 
{
	int d, s;
	
	s = size();
	
	if (s == 0)
		return ERR_DATA; // Error value

	d = data[right];
	
	right = (right - 1 + SIZE)%SIZE;
	
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
	left = right = -1;
}

int size() 
{
	if (left == -1)
		return 0;

	return (right+SIZE-left)%SIZE+1;
}

int vright()
{
	return right;
}

int vleft()
{
	return left;
}
