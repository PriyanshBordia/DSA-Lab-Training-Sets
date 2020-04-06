//Priyansh Bordia
//19UCS257

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// #include "stack.h"

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

char expr[100];
int where = 0;

char stack[100];
char postfix[100];
int top = -1;
int count = -1;

struct token 
{
    char kind;
    int value;
};

int main()
{
	stack[++top] = '#';
	// printf("______________________________________________________\n");
	// printf("Enter valid infix exp: ");
	fgets(expr, 99, stdin);

	struct token token;

	token = getNextToken();
	while (token.kind != FINISH)
	{
		if (token.kind == INT)
		{
			printf("%d ", token.value);
		}

		else if (token.kind == LPAR)
		{
			push(token.kind);
		}

		else if (token.kind == RPAR)
		{
			pop();
		}

		else if (!isalnum(token.kind))
		{
			push(token.kind);
		}

		else
		{
			printf("Invalid Input!!");
			exit(0);
		}
		token = getNextToken();
	}

	postfix[++count] = '\0';
	// display();
	printf("\n");
	return 0;
}

void pop()
{
	char c;
	while (stack[top] != LPAR)
		printf("%c ", stack[top--]);

	top--;
}

void push(char ch)
{
	stack[++top] = ch;
}

void skipWhite() 
{
    while (isspace(expr[where])) 
    	where++;
}

void skipDigits() 
{
    while (isdigit(expr[where])) 
    	where++;
}

struct token getNextToken() 
{
   	struct token token;
	skipWhite();
	
// ... ... CODE REMOVED ... ... ...
	if (isdigit(expr[where]))
	{
		sscanf(&expr[where], "%d", &token.value);
		token.kind = INT;
		skipDigits();
	}
	else
	{
		token.kind = expr[where];
		where++;
	}

	return token;
}
