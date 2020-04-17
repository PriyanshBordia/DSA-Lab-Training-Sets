#include "header.h"

int usedSize;  			// Part of the table that will be used
int divider2ndHashing;  // Step size for double hashing

double goldenNumber;

void initialise(int tableSize)
{
/* Find two suitable prime values for two division hashings funtions. */

/* usedSize should be a prime that is nearly as big as TBLSZ
		This sets the part of the table that is actually used to store pointers to strings
*/
	assert(TBLSZ > 1000);

	goldenNumber = (sqrt(5.0)-1)/2;   //changed the value according to  reema thareja `Knuth`

	int testing, prime, i;

	if (TBLSZ % 2 == 0)
		usedSize = TBLSZ-1;						//5999
	else
		usedSize = TBLSZ;

/* Begin with usedSize as big as TBLSZ and progressively lower it till it is a prime */
	while (usedSize > 2)
	{ 							// Keep trying
		i = 3;
		while (i*i <= usedSize)
		{												//77 * 77 = 5929
			if (usedSize%i == 0) /* No good */
			{
				usedSize -= 2;
				break;
			}
			i += 2;
		}

	    if (i*i > usedSize)
	        break;
	}

/* Pointers to data strings will be in indices 0 to usedSize.
Now find a prime to do probing over the table */

	divider2ndHashing = 2;

	while (divider2ndHashing * divider2ndHashing < usedSize)
		divider2ndHashing *= 2;
/* Similar to the previous search for a prime */

	while (divider2ndHashing > 2)
	{ 							// Keep trying
		i = 3;
		while (i*i <= divider2ndHashing)
		{
			if (divider2ndHashing%i == 0)
			{
				/* No good */
				divider2ndHashing -= 2;
				break;
			}

			i += 2;
		}

		if (i*i > divider2ndHashing)
 			     break;
	}
}

int goldenMultiplicative(int key)
{
/* Returns the primary location for the data using multiplication by golden number.
			See Reema Thareja Edn 2 page 468
*/
	double multiplier = goldenNumber - 1;
	double frac = (key*multiplier);
	int index = frac;

	frac = frac-index;
	index = frac*TBLSZ;

 	return index;
}

int makeNumber(char *str)
{
/* Construct a number from teh string */
	assert(str != NULL);

	int num = 0;

	int el = strlen(str);

	int i = el - 1; 			// Next letter to process

	if (el%2 == 0)
		el--; 		// Make it odd

	assert(el < 20 && el > 0);  // Too long a word

/* Computer specific limit on while */
    while(num < INT_MAX/26/26)
    {
		num = num * 26 + toupper(str[i])-toupper('A');
		i = (i+2) % el; 			// Choose alternate letters
	}

	num = 26 * num + el; 	// Include word length
	return num;
}

int divisionHash(int key, int probe)
{
	int step = key%divider2ndHashing;

    /* Linear hashing */
     return key % usedSize + probe;

    /* Double hashing */
    return key%usedSize + probe*step;
}
