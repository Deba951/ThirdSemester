#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;

void push(int data)
{
	int count;
    if (top == NULL)
    {
        top =(struct node *)malloc(sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }

void pop()
{
	int count;
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
}

void empty()
{
	int count;
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty");
}

int main()
{
    int no, ch, e;
 	printf("\n 1 - IsEmpty");
    printf("\n 2 - Push");
    printf("\n 3 - Pop");
    printf("\n 4 - Display");
    printf("\n 5 - Exit");
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
        	empty();
        	break;
        case 2:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
    	}
	}
	return 0;
}
