#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head;

void insertBegining()
{
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
		printf("\nOverflow\n");
	else
	{
		printf("Enter the value: ");
		scanf("%d",&item);
		if(head==NULL)
		{
			ptr->next=NULL;
			ptr->prev=NULL;
			ptr->data=item;
			head=ptr;
		}
		else
		{
			ptr->data=item;
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		}
		printf("\nNode inserted..\n");
	}	
}

void insertEnd()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
		printf("\nOverflow\n");
	else
	{
		printf("\nEnter the value: ");
		scanf("%d",&item),
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			ptr->prev=NULL;
			head=ptr;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=NULL;
		}
	}
	printf("Node inserted..\n");
} 

void deleteBegining()
{
	struct node *ptr;
	if(head==NULL)
		printf("\nUnderflow\n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nNode deleted\n");
	}
	else
	{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
		printf("\nNode deleted\n");
	}
}

void deleteLast()
{
	struct node *ptr;
	if(head==NULL)
		printf("\nUnderflow\n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nNode deleted..\n");
	}
	else
	{
		ptr=head;
		if(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->prev->next=NULL;
		free(ptr);
		printf("\nNode deleted..\n");
	}
}

void display()
{
	struct node *ptr;
	printf("\nPrinting values..\n");
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Insert at begining\n2.Insert at end\n3.Delete at begining\n4.Delete at end\n5.Display\n6.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertBegining();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				deleteBegining();
				break;
			case 4:
				deleteLast();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nPlease enter valid choice...\n");		
		}
	}
	return 0;
}
	
