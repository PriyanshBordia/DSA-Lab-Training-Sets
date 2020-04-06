//FUNCTIONS

struct token 
{
    char kind;
    int value;
};

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
