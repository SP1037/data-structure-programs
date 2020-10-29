#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
	int top;
	int capacity;
	int *array;
};

struct Stack *createStack(int capacity)
{
	struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
	if(!S)
	{
		return NULL;
	}
	S->top=-1;
	S->capacity=capacity;
	S->array=(int *)malloc(S->capacity*sizeof(int));
	if(!S->array)
	{
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
		return(S->array[S->top--]);
	}
}

int peek(struct Stack *S)
{
	if(isEmpty(S))
	{
		printf("\12Stack is Empty!!\12");
		return INT_MIN;
	}
	else
	{
		return(S->array[S->top]);
	}
}

void display(struct Stack *S)
{
	if(isEmpty(S))
	{
		printf("\12Stack is Empty\12");
		//return INT_MIN;
	}
	else
	{
		printf("\12Stack element are :\t");
		for(int i=0;i<=S->top;i++)
		{
			printf("%d\t",S->array[i]);
		}
		printf("\12");
	}
}

int main()
{
	int ch,ele,n;
	printf("\12Enter size of Stack : ");
	scanf("%d",&n);
	struct Stack *stk = createStack(n);
	while(1)
	{
		printf("\12Choose Option");
		printf("\n1.Push Element in Stack");
		printf("\n2.Pop Element from Stack");
		printf("\n3.Top Element of Stack");
		printf("\n4.Display all element of stack");
		printf("\n5.Quit");
		printf("\n\nEnter choice number only : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("\12Enter number to push in stack : ");
					 scanf("%d",&ele);
					 push(stk,ele);
					 break;
			case 2 : printf("\12Element popped from stack is %d\12",pop(stk));
					 break;
			case 3 : printf("\12Top Element from stack is %d\12",peek(stk));
					 break;
			case 4 : display(stk);
					 break;
			case 5 : exit(0);
					 break;
			default: printf("\12Wrong Choice entered\12");
		}
	}
	
	
	return 0;
}
