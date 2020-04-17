#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define TBLSZ 6000

void initialise(int tableSize);
int goldenMultiplicative(int key);
int makeNumber(char *str);
int divisionHash(int key, int probe);
