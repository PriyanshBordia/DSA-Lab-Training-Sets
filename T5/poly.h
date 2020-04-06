#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct term 
{
    struct term *nextP;
	int coeff;
	int power; 
};

/* Polynomial is a list or terms */
typedef struct term * polynomial;

/* Gives pointer to the first term in the polynomial list */ 
struct term *getFirstTerm (polynomial *prtToPoly);

/* Initialise a polynomial with no term */ 
void createPoly(polynomial *prtToPoly);

/* Insert a new term in polynomial list -- term with power should not exist */
void insertTerm(polynomial *prtToPoly, int coeff, int power);

/* Insert a new term in polynomial if none have exponent == power.
	Otherwise add coeff to term's coefficient.
	Do not forget to delete term if term's new coefficient == 0 
*/

void addTerm(polynomial *prtToPoly, int coeff, int power);

/* Gives next term in the polynomial after one referenced by termP */ 
struct term *getNextTerm(polynomial *prtToPoly, struct term *termP);

/* Prints the polynomial */
void printPoly(polynomial *prtToPoly);

/* Search for term with largest exponent value <= argument pow */ 
struct term *searchTerm(polynomial *prtToPoly, int pow);

/* Make a copy of src polynomial and make it accessible through destPoly */ 
void makePolyCopy(polynomial *srcPoly, polynomial *dstPoly);
