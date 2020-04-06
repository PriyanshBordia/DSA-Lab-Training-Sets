#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h>

void initDList();
struct chair *NewChair(char *name);
void insertChair(char *name);
char *removeChair(int pos);
char *whoInChair(int displacement);
int isEmpty();
