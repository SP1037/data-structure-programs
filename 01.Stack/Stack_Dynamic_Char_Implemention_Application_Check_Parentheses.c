#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct Stack{
	int top;
	int capacity;
	char *array;
};

struct Stack *createStack(int capacity)
{
	struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
	if(!S)
	{
		printf("\12Error in Stack Creation...\12");
		return NULL;
	}
	S->top=-1;
	S->capacity=capacity;
	S->array=(char *)malloc(S->capacity*sizeof(char));
	if(!S->array)
	{
		printf("\12Error in Stack Array Creation...\12");
		return NULL;
	}
	return S;
}

int isEmpty(struct Stack *S)
{
	return (S->top==-1);
}

int isFull(struct Stack *S)
{
	return (S->top==(S->capacity-1));
}

void push(struct Stack *S,char data)
{
	if(isFull(S))
	{
		printf("\12Stack is FULL\12");
	}
	else
	{
		S->array[++S->top]=data;
	}
}

char pop(struct Stack *S)
{
	if(isEmpty(S))
	{
		return '\0';
	}
	else
	{
		return (S->array[S->top--]);
	}
}

char peek(struct Stack *S)
{
	if(isEmpty(S))
	{
		return '0';
	}
	else
	{
		return (S->array[S->top]);
	}
}
/*
void display(struct Stack *S)
{
	if(isEmpty(S))
	{
		printf("\12Stack is Empty\12");
	}
	else
	{
		printf("\12Stack elements are :\t");
		for(int i=0;i<=S->top;i++)
		{
			printf("%c\t",S->array[i]);
		}
		printf("\12");
	}
}
*/

void deleteStack(struct Stack *S)
{
	if(S)
	{
		if(S->array)
		{
			free(S->array);
		}
		free(S);
	}
}

int matchPair(char a,char b)
{
	if(a =='(' && b ==')')
	{
		return 1;
	}
	else if(a == '{' && b == '}')
	{
		return 1;
	}
	else if(a == '[' && b == ']')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkExpression(char exp[])
{
	char temp,i;
	struct Stack *stk =createStack(10);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			push(stk,exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(isEmpty(stk))
			{
				printf("\12Right braces are more than left\12");
				return 0;
			}
			else
			{
				temp = pop(stk);
				if(!matchPair(temp,exp[i]))
				{
					printf("\12Mismatched braces are %c & %c\12",exp[i],temp);
					return 0;
				}
			}
		}
	}
	if(isEmpty(stk))
	{
		printf("\12Expression have matching paranthesis\12");
		return 1;
	}
	else
	{
		printf("\12Expression not have a matching paranthesis\12");
		return 0;
	}
}
int main()
{
	int n;
	//enter the expression here 
	n=checkExpression("()");
	if(n==1)
	{
		printf("\12Expression is valid\12");
	}
	else
	{
		printf("\12Expression is not valid\12");
	}
}
