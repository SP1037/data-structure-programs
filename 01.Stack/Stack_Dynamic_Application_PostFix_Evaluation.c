#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>

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
		printf("\12Error in Stack Creation\12");
		return NULL;
	}
	S->top=-1;
	S->capacity=capacity;
	S->array=(char *)malloc(S->capacity*sizeof(char));
	if(!S->array)
	{
		printf("\12Error in Stack Array Creation\12");
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

void push(struct Stack *S,int data)
{
	if(isFull(S))
	{
		printf("\12Stack is FULL!!\12");
	}
	else
	{
		S->array[++S->top]=data;
	}
}

int pop(struct Stack *S)
{
	if(isEmpty(S))
	{
		printf("\12Stack is Empty!!\12");
		return INT_MIN;
	}
	else
	{
		return (S->array[S->top--]);
	}
}

int postFixEvaluation(char exp[])
{
	int data,i;
	struct Stack *stk = createStack(10);
	for(i=0;exp[i];i++)
	{
		if(isdigit(exp[i]))
		{
			push(stk,exp[i]-'0');
		}
		else
		{
			int ftop = pop(stk);
			int ltop = pop(stk);
			switch(exp[i])
			{
				case '+' : push(stk,(ftop+ltop));
					   	   break;
				case '-' : push(stk,(ftop-ltop));
						   break;
				case '*' : push(stk,(ftop*ltop));
						   break;
				case '/' : push(stk,(ftop/ltop));
						   break;
			}
		}
	}
	return pop(stk);
}

int main()
{
	printf("\12PostFix evaluation of expression is %d\12",postFixEvaluation("123*+5-"));
	return 0;
}
