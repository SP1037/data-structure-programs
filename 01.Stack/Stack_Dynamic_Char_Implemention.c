#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

struct Stack{
	int top;
	int capacity;
	char *array;
};

struct Stack *createStack(int capacity){
	struct Stack *S =(struct Stack *)malloc(sizeof(struct Stack));
	if(!S)
	{
		printf("\12Stack Not Created\12");
		return NULL;
	}
	S->top=-1;
	S->capacity=capacity;
	S->array=(char *)malloc(S->capacity*sizeof(char));
	if(!S->array)
	{
		printf("\12Error in creating stack pointer array\12");
		return NULL;
	}
	return S;
}

int isEmpty(struct Stack *S)
{
	return(S->top==-1);
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
        printf("\12Stack is Empty\12");
        return '\0';
    }
    else
    {
        printf("\12Element popped is %c\12",S->array[S->top]);
        return (S->top--);
    }
    
}

char peek(struct Stack *S)
{
    if(isEmpty(S))
    {
        printf("\12Stack is Empty!!\12");
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
        printf("\12Stack is Empty!!\12");
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

int main()
{
    int ch,n;
    char ele;
    printf("Enter capcity of an Stack :  ");
    scanf("%d",&n);
    struct Stack *stk = createStack(n);
    while(1)
    {
        printf("\12Select Option\12");
        printf("\n1.Push a character");
        printf("\n2.Pop a character");
        printf("\n3.Top character from stack");
        printf("\n4.Display all characters from stack");
        printf("\n5.Delete Stack");
        printf("\n6.Quit");
        printf("\n\nEnter Option Choice Only : ");
        scanf("%d",&ch);
        fflush(stdin);
        switch(ch)
        {
            case 1 : printf("\12Enter a character to push : ");
                     scanf("%c",&ele);
                     push(stk,ele);
                     break;
            case 2 : printf("\12Index of Popped element from stack is %d\12",pop(stk));
                     break;
            case 3 : printf("\12Top element from stack is : %c\12",peek(stk));
                     break;
            case 4 : display(stk);
                     break;
            case 5 : deleteStack(stk);
                     printf("\12Stack Deleted...\nProgram Halted !!");
                     exit(0);
                     break;
            case 6 : exit(0);
                     break;
            default: printf("\12Wrong Choice Entered!!\12");
                     break;
            
        }
    }
    return 0;
}
