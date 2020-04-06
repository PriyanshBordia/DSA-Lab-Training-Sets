#include "stack.c"

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