#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;    

void beginsert()  
{  
    struct node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)    
        printf("\nOVERFLOW");    
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->next = head;  
        head = ptr;  
        printf("\nNode inserted");  
    }  
      
}  
void lastinsert()  
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)    
        printf("\nOVERFLOW");       
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL) 
                temp = temp -> next;   
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}

void begindelete()
{
	struct node *ptr;
	if(head==NULL)
		printf("List is empty");
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		printf("Noded deleted from the begining...\n");
	}
}

void lastdelete()
{
	struct node *ptr,*ptr1;
	if(head==NULL)
		printf("List is empty\n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nOnly node of the list is deleted..\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=NULL;
		free(ptr);
		printf("\nDeleted node from the last..\n");
	}
}  
  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)    
        printf("Nothing to print");    
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}
int main()  
{    
    int choice;
	while(1)   
    {    
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete fron begining\n4.Delete from last\n5.Display\n6.Exit\n");  
        printf("\nEnter your choice: \n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            	beginsert();      
            	break;  
            case 2:  
            	lastinsert();                   
            	break;  
            case 3:  
            	begindelete();         
            	break;
			case 4:  
            	lastdelete();         
            	break;  
            case 5:  
            	display();        
            	break;  
            case 6:  
            	exit(0);  
            	break;  
            default:  
            	printf("Please enter valid choice..");  
        }  
    }
	return 0; 
}
