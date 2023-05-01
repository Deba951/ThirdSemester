#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void traverse()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty!!!\n");
        return;
    }
    do
    {
        printf("%3d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void insertFirst(int item)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        ptr->data = item;
        ptr->next = ptr;
        head = ptr;
    }
    ptr->data = item;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
}

void insertLast(int item)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        ptr->data = item;
        ptr->next = ptr;
        head = ptr;
    }
    ptr->data = item;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty!!!\n");
    }
    else if (head->next == head)
    {
        printf("Deleted item is %d\n", head->data);
        head = NULL;
        free(head);
    }
    else
    {
        struct Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        printf("Deleted item is %d\n", head->data);
        p->next = head->next;

        free(head);
        head = p->next;
    }
}

void deleteLast()
{
    struct Node *ptr, *p;
    if (head == NULL)
    {
        printf("List is empty!!!\n");
    }
    else if (head->next == head)
    {
        printf("Deleted item is %d\n", head->data);
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            p = ptr;
            ptr = ptr->next;
        }
        p->next = ptr->next;
        printf("Deleted item is %d\n", ptr->data);
        free(ptr);
    }
}

int main()
{
    int t, p, q, s;
    while (1)
    {
        printf("\n");
        printf("Enter 1 to insert at begining\n");
        printf("Enter 2 to insert at end\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to delete from first\n");
        printf("Enter 5 to delete from last\n");
        printf("Enter 6 to exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("Enter the item: ");
            scanf("%d", &p);
            insertFirst(p);
            break;
        case 2:
            printf("Enter the item: ");
            scanf("%d", &q);
            insertLast(q);
            break;
        case 3:
            traverse();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}
