//FUNCTIONS

#include "dlink.h"

struct chair 
{
    struct chair *leftChair;
    char *player;
    struct chair *rightChair;
};

struct chair *pointAtChair0;
int No_of_players = 0;

void initDList()
{
	pointAtChair0 = NULL;
}

struct chair *NewChair(char *name)
{
	struct chair *chair = malloc(sizeof(struct chair));
	
	assert (chair != NULL);

	chair->leftChair = NULL;
	chair->player = name;
	chair->rightChair = NULL;

	return chair;
}

void insertChair(char *name)
{
	struct chair *newchair = NewChair(name);

	assert (newchair != NULL);

	if (pointAtChair0 == NULL)
	{
		pointAtChair0 = newchair; 
	}

	else if (pointAtChair0->leftChair == NULL)
	{
		struct chair *temp = pointAtChair0;

		temp->rightChair = newchair;

		newchair->rightChair = pointAtChair0;
		newchair->leftChair = temp;
		
		temp->leftChair = newchair;
	}

	else
	{
		struct chair *temp = pointAtChair0->leftChair;

		assert (temp != NULL);
		
		temp->rightChair = newchair;

		newchair->rightChair = pointAtChair0;
		newchair->leftChair = temp;
		
		pointAtChair0->leftChair = newchair;
	}

	No_of_players++;
}

char *removeChair(int displacement)
{
	struct chair *cur_chair = pointAtChair0;
	struct chair *prev_chair = pointAtChair0;

	
	if (No_of_players == 1)
	{
		char *name = pointAtChair0->player;

		No_of_players--;

		// free(cur_chair);

		return name;
	}


	int count = 0;

	if (displacement > 0)
	{
		while (count < displacement)
		{
			prev_chair = cur_chair;
			cur_chair = cur_chair->rightChair;
			count++;
		}
		
		if (cur_chair == pointAtChair0) 
		{
			pointAtChair0 = pointAtChair0->rightChair;
		}

		prev_chair->rightChair = cur_chair->rightChair;

		cur_chair->rightChair->leftChair = prev_chair;
	}

	else
	{
		displacement *= -1; 
		while (count < displacement)
		{
			prev_chair = cur_chair;
			cur_chair = cur_chair->leftChair;
			count++;
		}

		if (cur_chair == pointAtChair0) 
		{
			pointAtChair0 = pointAtChair0->leftChair;
		}

		prev_chair->leftChair = cur_chair->leftChair;

		cur_chair->leftChair->rightChair = prev_chair;	
	}

	char *name = cur_chair->player;

	No_of_players--;

	// free(cur_chair);

	return name;
}

char *whoInChair(int displacement) 
{
	if (!isEmpty())
		return pointAtChair0->player;
	else 
		return "None found";
}

int isEmpty()
{
	if (No_of_players == 0)
		return 1;
	else
		return 0;	
}
