{
	if (displacement == 0)
	{
		if (No_of_players == 1)
		{
			char *name = pointAtChair0->player;

			free(pointAtChair0);

			No_of_players--; 
			
			return name;
		}

		else if (No_of_players == 2)
		{
			struct chair *temp = pointAtChair0;

			pointAtChair0 = pointAtChair0->right;
			pointAtChair0->rightChair = pointAtChair0->leftChair = NULL;

			free(temp);

			char *name = pointAtChair0->player;

			free(pointAtChair0);

			No_of_players--; 
			
			return name;
		}
	}

	else if (displacement == 1)
	{
		struct chair *prev = NULL;
		struct chair *cur = pointAtChair0;

		if (No_of_players > 2)
		{
			pointAtChair0 = cur->rightChair;
			pointAtChair0->leftChair = prev;

			prev->rightChair = cur->rightChair;
			cur->rightChair = NULL;
		}

		else
		{
			pointAtChair0 = pointAtChair0->rightChair;
		}
	}

	else
	{
		int count = 1;
		if (displacement < 0)
		{
			displacement *= -1; 
			while(count < displacement)
			{
				prev = cur;
				cur = cur->leftChair;
				count++;
			}
		}

		else
		{
			while(count < displacement)
			{
				prev = cur;
				cur = cur->rightChair;
				count++;
			}
		}

		prev->rightChair = cur->rightChair;
		cur->rightChair->leftChair = prev; 
		cur->rightChair = NULL;
	}

	char *name = cur->player;

	free(cur);

	No_of_players--; 
		
	return name;
}