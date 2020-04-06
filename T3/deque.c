//FUNTIONS

#include "deque.h"

struct node 
{
	int data;
	struct node *nextL;
	struct node *nextR;
};

/* storage allocated here */
struct node hdr;

void init() 
{
	// unused 
	hdr.data = 0; 
	hdr.nextL = hdr.nextR = NULL;
}

void joinL(int d) 
{
	printf("Going to join %d on left\n", d);
	struct node *new = (struct node *)malloc(sizeof(struct node));
	
	assert (new != NULL); // Stop if problem
	
	new->data = d;

//implementation of assert
	if (hdr.nextL == NULL) 
	{
		assert (hdr.nextR == NULL);

		hdr.nextL = hdr.nextR = new;
		new->nextL = new->nextR = NULL;
		
		printf("Joined %d on left\n", d);
		
		return;
	}
	
	assert (hdr.nextR != NULL);
	assert (hdr.nextL->nextL == NULL);

	hdr.nextL->nextL = new;
	new->nextR = hdr.nextL;
	new->nextL = NULL;
	hdr.nextL = new;
	printf("Joined %d on left\n", d);	
}

void joinR(int d) 
{
	printf("Going to join %d on right\n", d);
	struct node *new = malloc(sizeof(struct node));
	
	assert (new != NULL); 		// Stop if problem
	
	new->data = d;

	if (hdr.nextR == NULL) 
	{
		assert(hdr.nextL == NULL);

		hdr.nextR = hdr.nextL = new;
		new->nextR = new->nextL = NULL;
		
		printf("Joined %d on right\n", d);
	}
	
	assert(hdr.nextL != NULL);

	assert(hdr.nextR->nextR == NULL);

	hdr.nextR->nextR = new;
	new->nextL = hdr.nextR;
	new->nextR = NULL;
	hdr.nextR = new;
	printf("Joined %d on right\n", d);	
	// return;
}

int leaveL() 
{
	// Unimplemented

	struct node *tmp;
	printf("Someone leaving from Left\n");

	assert(hdr.nextL != NULL && hdr.nextR != NULL);
	
	int d = hdr.nextL->data;
	tmp = hdr.nextL->nextR;

	if (tmp != NULL)
		tmp->nextL = NULL;
	
	free(hdr.nextL);
	
	hdr.nextL = tmp;

	printf("From Left %d left\n", d);
	if (tmp == NULL)
		hdr.nextR = NULL;

	assert (tmp != NULL || hdr.nextR == NULL);

	return d; 
}

int leaveR() 
{
	struct node *tmp;
	printf("Someone leaving from Right\n");
	
	assert(hdr.nextL != NULL && hdr.nextR != NULL);
	
	int d = hdr.nextR->data;
	
	tmp = hdr.nextR->nextL;
	
	if (tmp != NULL)
		tmp->nextR = NULL;
	
	free(hdr.nextR);
	
	hdr.nextR = tmp;
	printf("From right %d left\n", d);
	
	if (tmp == NULL)
		hdr.nextL = NULL;
	
	assert (tmp != NULL || hdr.nextL == NULL);	
	
	return d;
}
 
int size() 
{
	int i = 0;
	struct node *ptr = hdr.nextL;
	
	while (ptr != NULL) 
	{
		i++; 
		ptr = ptr->nextR;
	}
	
	return i;
}

void push(char c)
{
	joinL(c);
}

char pop()
{
	return  (char)leaveL();
}

int isEmpty()
{
	if (hdr.data == '#')
		return 1;
	else
		return 0;
}
/* ADT interface functions */
/* THink of hdr as if it is on top 
of all member nodes of deque.
Left and right of header is not symmetric to
those of member nodes */
