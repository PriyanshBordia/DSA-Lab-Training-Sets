//Priyansh Bordia
//19UCS257

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LPAR '('
#define RPAR ')'
#define PLUS '+'
#define SUB '-'
#define DIV '/'
#define MULT '*'
#define MOD '%'
#define FINISH '\0'
#define INT '0'

void pop();
void push(char ch);
void convert();
void display();
struct token getNextToken();