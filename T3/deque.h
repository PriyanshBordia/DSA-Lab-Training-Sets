#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Defiend in some othert file */
extern struct node hdr;

/* ADT interface functions */
void init();

void joinL(int d);
void joinR(int d);

int leaveL();
int leaveR();
 
int size();

void push(char ch);
char pop();
int isEmpty();