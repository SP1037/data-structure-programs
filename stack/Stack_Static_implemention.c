#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 5
int stack[SIZE],top=-1;

int isEmpty()
{
	return (top==-1);
}

int isFull()
{
	return (top==(SIZE-1));
}

void push(int data)
{
	if(isFull())
	{
		printf("\12Stack is FULL!!\12");
	}
	else
	{
		stack[++top]=data;
		printf("\12Inserted Element is : %d\12",data);
	}
}

int pop()
{
	if(isEmpty())
	{
		printf("\12Stack is Empty!!\12");
	}
	else
	{
		return(stack[top--]);
	}
}

int peek()
{
	
	if(isEmpty())
	{
		printf("\12Stack is Empty!!\12");
	}
	else
	{
		return (stack[top]);
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
			printf("%d\t",stack[i]);
		}
		printf("\12");
	}
}


int main()
{
	int ch,ele;
	while(1)
	{
		printf("\12Choose option choice only");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Top Element");
		printf("\n4.Display all element");
		printf("\n5.Quit");
		printf("\12\nEnter choice number only : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("\12Enter element to push : ");
			  		 scanf("%d",&ele);
			  		 push(ele);
			  		 break;
			case 2 : printf("\12Popped Element is %d\12",pop());
					 break;
			case 3 : printf("\12Top Element is %d\12",peek());
					 break;
			case 4 : display();
					 break;
			case 5 : exit(0);
					 break;
			default : printf("\12Wrong Choice Number Entered");
					  break;
		}
	}
	return 0;
}
