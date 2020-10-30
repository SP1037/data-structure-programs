#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define SIZE 5

int top=-1;
char Stack[SIZE];

int isEmpty()
{
	return (top==-1);
}

int isFull()
{
	return (top==(SIZE-1));
}

void push(char data)
{
	if(isFull())
	{
		printf("\12Stack is FULL!!\12");
	}
	else
	{
		Stack[++top]=data;
	}
}

int pop()
{
	if(isEmpty())
	{
		printf("\12Stack is Empty!!\12");
		return INT_MIN;
	}
	else
	{
		printf("\12Popped character is %c\12",Stack[top]);
		return top--;
	}
}

char peek()
{
	if(isEmpty())
	{
		printf("\12Stack is Empty!!\12");
		return '\0';
	}
	else
	{
		return (Stack[top]);
	}
}

void display()
{
	if(isEmpty())
	{
		printf("\12Stack is Empty!!\12");
	}
	else
	{
		printf("\12Stack Elements are :\t");
		for(int i=0;i<=top;i++)
		{
			printf("%c\t",Stack[i]);
		}
		printf("\12");
	}
}

int main()
{
	int ch,n;
	char ele;
	while(1)
	{
		printf("\12Choose Correct Option");
		printf("\n1.Push to Stack");
		printf("\n2.Pop from Stack");
		printf("\n3.Top Character from stack");
		printf("\n4.Display all character from stack");
		printf("\n5.Quit");	
		printf("\n\nEnter choice number only : ");
		scanf("%d",&ch);
		fflush(stdin);
		switch(ch)
		{
			case 1 : printf("\12Enter Character : ");
					 scanf("%c",&ele);
					 push(ele);
					 break;
			case 2 : printf("\12Index of popped element is %d\12",pop());
					 break;
			case 3 : printf("\12Top character form stack is %c\12",peek());
					 break;
			case 4 : display();
					 break;
			case 5 : exit(0);
					 break;
			default: printf("\12Wrong Choice selected\12"); 
		}
	}
	return 0;
}
