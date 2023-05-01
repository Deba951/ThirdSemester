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
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)    
        printf("\nEmpty List\n");    
    else  
    {   
        printf("\nEnter item which you want to search: \n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;
				break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)    
            printf("Item not found\n");   
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
        printf("\n1.Insert in begining\n2.Insert at last\n3.Search for an element\n4.Display\n5.Exit\n");  
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
            	search();         
            	break;  
            case 4:  
            	display();        
            	break;  
            case 5:  
            	exit(0);  
            	break;  
            default:  
            	printf("Please enter valid choice..");  
        }  
    }
	return 0; 
}
