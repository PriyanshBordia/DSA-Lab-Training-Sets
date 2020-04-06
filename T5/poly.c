#include <stdio.h>
#include <stdlib.h>
#include "poly.h" 
 
/* Gives pointer to the  first term in the polynomial list */
struct term *getFirstTerm (polynomial *ptrToPoly) 
{
	assert(ptrToPoly != NULL); 
	assert(*ptrToPoly != NULL); 

	return (*ptrToPoly)->nextP;
}

/* Initialise a polynomial with no term */ 
void createPoly(polynomial *ptrToPoly) 
{
	assert(ptrToPoly!=NULL);

	(*ptrToPoly) = malloc(sizeof(struct term)); 
	(*ptrToPoly)->nextP = NULL;
}

/* Insert a new term in polynomial list -- term with power should not exist */
void insertTerm(polynomial *ptrToPoly, int coeff, int power) 
{
	struct term *ptr, *prev;
	struct term *newTerm = malloc(sizeof(struct term)); 
	newTerm->coeff = coeff;
	
	newTerm->power = power;
	
	ptr = getFirstTerm(ptrToPoly);
	prev = *ptrToPoly;

/* Notice that ptr is used only if not NULL */ 
	while (ptr != NULL && power < ptr->power) 
	{
	// Find the right location for new node 
		prev = ptr;
		ptr = getNextTerm(ptrToPoly, ptr);
	}
	
	assert(ptr == NULL || ptr->power != power); 
	
	newTerm->nextP = ptr;
	prev->nextP = newTerm;
}
/*
void addTerm(polynomial *prtToPoly, int coeff, int power)
{
	if (term->power )

}
*/
/* Gives next term in the polynomial after one referenced by termP */ 
struct term *getNextTerm(polynomial *ptrToPoly, struct term *termP) 
{
	assert(termP != NULL);

	return termP->nextP; 
}

/* Available here but not through poly.h */ 
static void printTerm(struct term *term) 
{
	printf("%+d*X^%d ", term->coeff,term->power); 
}

/* Prints the polynomial */
void printPoly(polynomial *ptrToPoly) 
{
	struct term *prnt = getFirstTerm(ptrToPoly); 

	while (prnt!=NULL)
	{
	    printTerm(prnt);
		prnt = getNextTerm(ptrToPoly, prnt); 
	}

	printf("\n"); 
}

struct term *searchTerm(polynomial *prtToPoly, int pow)
{
	struct term **temp = prtToPoly;
	
	assert ((*temp) != NULL);

	while ((*temp) != NULL)
	{
		if ((*temp)->power <= pow)
			break;

		*temp = (*temp)->nextP;
	}

	return (*temp);
}

void makePolyCopy(polynomial *srcPoly, polynomial *dstPoly)
{
	polynomial *temp = srcPoly;

	struct term *cpterm1;
	
	createPoly(&(*dstPoly));

	cpterm1 = getFirstTerm(&(*srcPoly));
	while (cpterm1 != NULL)
	{
		insertTerm(&(*dstPoly), cpterm1->coeff, cpterm1->power);
				
		cpterm1 = getNextTerm(&(*srcPoly), cpterm1);
	}
}