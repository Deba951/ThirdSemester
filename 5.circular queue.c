#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int arr[SIZE];
int front=0;
int rear=0;
int isFull()
{
	if((rear+1)%SIZE==front)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
void insert(int item)
{
	if(!isFull())
	{
		rear=(rear+1)%SIZE;
		arr[rear]=item;
	}
	else
	{
		printf("\nQueue is full\n");	
	}
}
int delete()
{
	if(!isEmpty())
	{
		front=(front+1)%SIZE;
		int data=arr[front];
		return data;
	}
	else
	{
		printf("\nQueue is empty\n");
		return -999;
	}
}
void display()
{
	int i;
	if(!isEmpty())
	{
		for(i=(front+1)%SIZE;i!=rear;i=(i+1)%SIZE)
			printf("%3d",arr[i]);
		printf("%3d\n",arr[i]);
	}
	else
		printf("Queue is empty\n");
}
int main()
{
	int ch;
	while(1)
	{
		printf("1: INSERT\n");
		printf("2: DELETE\n");
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
				insert(item);
				break;
			case 2:
				data=delete();
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
