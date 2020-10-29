#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 5

int Queue[SIZE],front=-1,rear=-1;

int isEmpty()
{
	return (front==-1);
}

int isFull()
{
	return (rear==(SIZE-1));
}

int frontElemnt()
{
	return(Queue[front]);
}

int rearElement()
{
	return (Queue[rear]);
}

void enQueue(int data)
{
	if(isFull())
	{
		printf("\12Queue is FULL!!\12");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		Queue[rear]=data;
		printf("\12Inserted : %d\12",data);
		
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
		printf("\12Deleted : %d\12",Queue[front]);
		front++;
		if(front>rear)
		{
			front=rear=1;
		}
	}
}

void display()
{
	if(isEmpty())
	{
		printf("\12Queue is Empty!!\12");
	}
	else
	{
		printf("\12Queue elements are :\t");
		for(int i=front;i<=rear;i++)
		{
			printf("%d\t",Queue[i]);
		}
		printf("\12");
	}
}

int main()
{
	int ch ,ele;
	while(1)
	{
		printf("\12Enter Your Choice\12");
		printf("\n1.enQueue");
		printf("\n2.deQueue");
		printf("\n3.Display");
		printf("\n4.Quit");
		printf("\12\12Enter choice number only : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("\12Enter element to add queue : ");
					 scanf("%d",&ele);
					 enQueue(ele);
					 break;
			case 2 : deQueue();
					 break;
			case 3 : display();
					 break;
			case 4 : exit(0);
					 break;
			default:printf("\12Enter correct choice Number\12");
					break;
		}
	}
	
	return 0;
}
