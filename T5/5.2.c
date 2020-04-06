#include "poly.h"

polynomial poly1;
polynomial poly2;
polynomial result;

struct term *term1P, *term2P;

int main(void) 
{
/* Construct polynomial 1 */

	createPoly(&poly1); 	// Get the start pointer set 
	insertTerm(&poly1, 10, 1000);
	insertTerm(&poly1, 100, 2000); 
	insertTerm(&poly1, -10, 500);
	insertTerm(&poly1, -10, -1000); 

	printf("Polynomial_1 = ");
	
	printPoly(&poly1);

// Copying Polynomial
	createPoly(&poly2); 

	makePolyCopy(&poly1, &poly2);

	printf("Copy Poly: ");
	printPoly(&poly2);

/* Construct result = poly1 + poly2 */

	createPoly(&result);

	term1P = getFirstTerm(&poly1);
	term2P = getFirstTerm(&poly2);

	while (term1P != NULL || term2P != NULL) 
	{ 
		if (term1P == NULL) 
		{
			insertTerm(&result, term2P->coeff, term2P->power); 
			term2P = getNextTerm(&poly2, term2P);
			continue;
		}
		
		if (term2P == NULL) 
		{
			insertTerm(&result, term1P->coeff, term1P->power); 
			term1P = getNextTerm(&poly1, term1P);
			continue;
		}

		if (term1P->power == term2P->power) 
		{
			if (term1P->coeff + term2P->coeff != 0)
				insertTerm(&result, term2P->coeff + term1P->coeff, term2P->power);

			term2P = getNextTerm(&poly2, term2P);
			term1P = getNextTerm(&poly1, term1P);
			
			continue; 
		}

		if (term1P->power > term2P->power) 
		{
			insertTerm(&result, term1P->coeff, term1P->power); 
			term1P = getNextTerm(&poly1, term1P);
			continue;
		}

		if (term1P->power < term2P->power) 
		{
			insertTerm(&result, term2P->coeff, term2P->power); 
			term2P = getNextTerm(&poly2, term2P);
			continue;
		} 
	}

	printf("_______________________________________________________________________________________\n");
	printf("Polynomial_1 + Polynomial_2 = "); 
	
	printPoly(&result);
	
	printf("_______________________________________________________________________________________\n");
	
	printf("_______________________________________________________________________________________\n");
	printf("Polynomial_2 - Polynomial_1 = 0\n"); 

	printf("_______________________________________________________________________________________\n");

	
	// printPoly(&result2);
	
	return 0; 
}