#include "header.h"

char *table[TBLSZ];

int main(void)
{
	FILE *collection = fopen("collection", "r");

	assert(collection != NULL);

	char strg[100];
	char * dataP;

	int loc, collisions = 0, noCollisions = 0;
	int el, reTry, rehash, filled;

	initialise(TBLSZ);

	int count = 0;
	while (fgets(strg,90,collection))
	{
		el= strlen(strg)-1;
		strg[el] = '\0';

		printf("%s\n", strg);

		dataP = malloc(strlen(strg)+1);

		assert(dataP != NULL);

		strcpy(dataP, strg);
		reTry = 0;

		count++;
		/*while (rehash < 100)
		{
			count++;

			loc = divisionHash(makeNumber(strg), reTry);

			if (table[loc] != NULL)
			{
		        reTry++;
		        collisions++;
		        continue;
	        }
	        else
	        {
		        filled++;
		        table[loc] = dataP;
				break;
			}
		}*/
	}

	printf("%d\n", count);
	printf("Total collisions %d\n", collisions);
	printf("Unused %d\n", TBLSZ-filled);
	printf("Filled %d\n", filled);
	return 0;
}
