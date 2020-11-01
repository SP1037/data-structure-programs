#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>

#define SIZE 5

int front =-1,rear=-1;
char Qu[SIZE];

int isEmpty()
{
	return (rear==-1);
}

int isFull()
{
	return (rear==(SIZE-1));
}

char rearElement()
{
	return (Qu[rear]);
}

char frontElement()
{
	return (Qu[front]);
}

void enQueue(char data)
{
	if(isFull())
	{
		printf("\12Queue is FULL!!\12");
	}
	else
	{
		Qu[++rear]=data;
		printf("\12Inserted : %c\12",Qu[rear]);
		if(front==-1)
		{
			front=0;
		}
	}
}

void deQueue()
{
	if(isEmpty())
	{
		printf("\12Queue is Empty!!\12");
	}
	else
	{
		printf("\12Deleted : %c\12",Qu[front]);
		front++;
		if(front>rear)
		{
			front=rear=-1;
		}
	}
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("\12Queue is Empty!!\12");
	}
	else
	{
		printf("\12Queue elements are :\t");
		for(i=front;i<=rear;i++)
		{
			printf("%c\t",Qu[i]);
		}
		printf("\12");
	}
}

int main()
{
	int ch;
	char ele;
	while(1)
	{
		printf("\12Choose option\12");
		printf("\n1.enQueue");
		printf("\n2.deQueue");
		printf("\n3.Display");
		printf("\n4.First Element");
		printf("\n5.Last Element");
		printf("\n6.Quit");
		printf("\n\nEnter number choice only : ");
		scanf("%d",&ch);
		fflush(stdin);
		switch(ch)
		{
			case 1 : printf("\12Enter element to enqueue : ");
					 scanf("%c",&ele);
					 enQueue(ele);
					 break;
			case 2 : deQueue(ele);
					 break;
			case 3 : display();
					 break;
			case 4 : printf("\12First element is %c\12",frontElement());
					 break;
			case 5 : printf("\12Last Element is %c\12",rearElement());
					 break;
			case 6 : exit(0);
					 break;
			default: printf("\12Enter correct number.\12");
					 break;
		}
	}
	return 0;
}
