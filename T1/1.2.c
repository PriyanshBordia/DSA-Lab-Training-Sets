#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define LPAR '('
#define RPAR ')'
#define PLUS '+'
#define SUB '-'
#define DIV '/'
#define MULT '*'
#define MOD '%'
#define FINISH '\0'
#define INT '0'

struct token 
{
    char kind;
    int value;
};

char expr[100];
int where = 0;

int stack[100];
int top = -1;

struct token getNextToken();
int pop();
void push(int n);
void evaluate(char ch);

int main()
{
	// printf("Enter Postfix Exp: ");
	fgets(expr, 99, stdin);

	struct token token;

	token = getNextToken(); 

	while (token.kind != FINISH) 
	{
		// printf("%c", token.kind); 
		if (token.kind == INT)
		{
			// printf(" %d\n", token.value); 
			push(token.value);
		}

		else if (!isalnum(token.kind))
		{
			evaluate(token.kind);
		}
		
		token = getNextToken();
		// printf("Top: %d\n", stack[top]); 			// check for top most element of stack 
	}

	printf("Ans: %d\n", stack[top]);

	return 0;
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

int pop()
{
	return stack[top--];
}

void push(int n)
{
	stack[++top] = n;
}

int calculate(int a, int b, char ch)
{
	switch (ch)
	{
		case '+': return a + b;

		case '-': return b - a;
		
		case '*': return a * b;

		case '/': return b / a;

		case '%': return b % a;

		case '^': return pow(a,b);

		default : return 0;
	}
}

void evaluate(char ch)
{
	int op1, op2;
	
	op1 = pop();
	op2 = pop();		

	int val = calculate(op1, op2, ch);
	push(val);


}