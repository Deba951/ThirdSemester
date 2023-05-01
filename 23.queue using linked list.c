#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *rear=NULL,*front=NULL;

struct Node *newNode(int item){
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->data=item;
	ptr->next=NULL;
}

void isEmpty()
{
	if(front==NULL)
		printf("\nQueue is empty..");
	else
		printf("\nQueue is not empty..\n");
}
void push(int item){
	struct Node *curr=newNode(item);
	if(rear==NULL){
		rear=front=curr;
		return;
	}
	rear->next=curr;
	rear=curr;
}

void pop(){
	if(front==NULL){
		printf("Empty list\n");
		return;
	}
	if(front->next==NULL){
		printf("Deleted item: %d\n",front->data);
		free(front);
		front=rear=NULL;
		return;
	}
	struct Node *temp=front;
	front=front->next;
	printf("Deleted item: %d\n",temp->data);
	free(temp);
}

void display(){
	if(front==NULL){
		printf("Empty list\n");
		return;
	}
	struct Node *temp=front;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}	
}

int main(){
	int option,item;
	while(1){
		printf("\n1.IsEmpty\n2.Push\n3.Pop\n4.Display\n");
		printf("Enter option: ");
		scanf("%d",&option);
		switch(option){
			case 1: isEmpty();
					break;
			case 2: printf("Enter item: ");
					scanf("%d",&item);
					push(item);
					break;
			case 3: pop();
					break;
			case 4: display();
					break;
			default: exit(0);
		}
	}
	return 0;
}
