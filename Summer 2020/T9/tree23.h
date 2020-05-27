#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h>

struct node23 *toRoot;

struct node23 
{
	int data[2];
    struct node23 *subT[3];
    int countKeys;
};

typedef struct node23 *node23p;
int search(int val);
void insert(int val);
void rid(int val);
void display();