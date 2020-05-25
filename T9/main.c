#include "rajasthanGeography.h"

char *squeeze(char *begin, char *end) 
{
	/* Squeeze out superflous white spaces */
	char *last, *start = begin;
	int first = 0;

	/* Set start to the first non space */ 
	while (isspace(*start)) 
		start++;

	/* locate last non space */
	while (isspace(*end) || *end == '\0')
		*(end--) = '\0'; 
	
	last = end;
	
	while (last >= start) 
	{
		while (first && isspace(*last))
			last--;
		
		first = isspace(*last);
		*(end--) = *(last--);
	} 
	
	return end+1;
}

void setUpGraph(void) 
{
    int i, distance;

	FILE *cities = fopen("cities", "r"); 
	FILE *roads = fopen("roads", "r"); 

	assert(cities != NULL && roads != NULL); 

	char name[100];
    char *roadStart, *roadEnd, *kms;
    struct link *ll;
	
	while (fgets(name, 99, cities)) 
	{
		if (strlen(name) < 2) 
			break; 

		name[strlen(name)-1] = '\0';
		
		if (makeTown(squeeze(name, name+strlen(name))) == NULL)
		    break; 	// Data structure full
	}

	while (fgets(name, 99, roads)) 
	{
		if (strlen(name) < 4) 
			break; 

		name[strlen(name)-1] = '\0'; 
		roadStart = kms = name;
	
		while (!isdigit(*kms)) 
			kms++; 

		*(kms-1) = '\0';

		roadEnd = kms;
		
		sscanf(kms, "%d", &distance);

		while (!isspace(*roadEnd)) 
			roadEnd++; 

		linkTowns(squeeze(roadStart,roadStart + strlen(roadStart)), squeeze(roadEnd, roadEnd + strlen(roadEnd)), distance);
	}
}

void findShortestDistances(struct town *here) 
{ 
	/* Distances to other towns from HERE */ 
	int townsIdx, update = 0;
	
	if (here == NULL)
        return;
    
    int nextDist;
    struct town *newFound, *there;

    // < 20 Lines of C code removed. Student to add code here for Task 03 >

	/* recursive call from town closest to the starting town Whose distance is not yet final */
    findShortestDistances(there);
}

int main(void) 
{
    int townsIdx;
	struct town *rupaNangal;
	
	setUpGraph();

	rupaNangal = getTown("Rupa ki Nangal"); 
	assert(rupaNangal != NULL); 
	
	setFinalDist(rupaNangal, 0); 

	findShortestDistances(rupaNangal);
	
	/* Print distances. */
	for (townsIdx = 0; townsIdx < towns; townsIdx++) 
	{
		printf("Town %s is ", getName(townships[townsIdx])); 

		if (isDistanceFinal(townships[townsIdx]))
			printf("%d kms from LNMIIT\n", getDistFromStart(townships[townsIdx]));
		else
			printf("unconnected to LNMIIT in this graph\n");	
	}	
	
	return 0; 
}


