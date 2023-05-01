#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int arr[SIZE];
int top=-1;
int isFull()
{
	if(top==SIZE-1)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(int item)
{
	if(isFull())
		printf("\nStack is full\n");
	else
	{
		top=top+1;
		arr[top]=item;
	}
}
int pop()
{
	if(isEmpty())
	{
		printf("\nStack is empty\n");
		return 0;
	}
	else
	{
		int data=arr[top];
		top=top-1;
		return data;
	}
}
int peek()
{
	if(isEmpty())
	{
		printf("\nStack is empty\n");
		return 0;
	}
	else
	{
		int data=arr[top];
		return data;
	}
}
void display()
{
	if(isEmpty())
		printf("\nStack is empty\n");
	else
	{
		int i;
		for(i=top;i>=0;i--)
			printf("\n%d\n",arr[i]);	
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("1: PUSH\n");
		printf("2: POP\n");
		printf("3: DISPLAY\n");
		printf("4: EXIT\n");
		printf("Enter your choice: \n");
		scanf("%d",&ch);
		int data;
		switch(ch)
		{
			case 1:
				printf("Enter item which is to be inserted: ");
				int item;
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				data=pop();
				if(data!=-999)
				{
					printf("Deleted item =%d\n",data);
				}
				break;
			case 3:
				display();
				break;
			default:
				exit(1);			
		}
	}
}

