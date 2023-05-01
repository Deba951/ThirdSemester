#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
};
struct TreeNode *root = NULL;

void insert(int item)
{
    struct TreeNode *curr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    curr->lchild = NULL;
    curr->data = item;
    curr->rchild = NULL;
    if (root == NULL)
    {
        root = curr;
        return;
    }
    struct TreeNode *temp = root, *parent;
    while (temp != NULL)
    {
        parent = temp;
        if (item > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    if (item > parent->data)
    {
        parent->rchild = curr;
    }
    else
    {
        parent->lchild = curr;
    }
}

void search(int item)
{
    int i = 0,flag=1;
    if (root == NULL)
    {
        printf("Empty Tree!!!\n");
        return;
    }
    struct TreeNode *temp = root;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("Element %d is present\n",item);
            flag = 0;
            break;
        }
        else if (item < temp->data)
        {
            temp = temp->lchild;
        }
        else
        {
            temp = temp->rchild;
        }
        i++;
    }
    if(flag==1){
        printf("Element %d is not present in the tree!!!\n", item);
    }
}
void printInorder(struct TreeNode *ptr)
{
    if (ptr == NULL)
        return;

    printInorder(ptr->lchild);
    printf("%d\n", ptr->data);
    printInorder(ptr->rchild);
}
void printPreorder(struct TreeNode *ptr)
{
    if (ptr == NULL)
        return;

    printf("%d\n", ptr->data);
    printPreorder(ptr->lchild);
    printPreorder(ptr->rchild);
}
void printPostorder(struct TreeNode *ptr)
{
    if (ptr == NULL)
        return;

    printPostorder(ptr->lchild);
    printPostorder(ptr->rchild);
    printf("%d\n", ptr->data);
}

int main()
{
    int t, p, q, s;
    while (1)
    {
        printf("\n");
        printf("Enter 1 to insert\n");
        printf("Enter 2 to search an item\n");
        printf("Enter 3 to display inorder\n");
        printf("Enter 4 to display preorder\n");
        printf("Enter 5 to display postorder\n");
        printf("Enter 6 to exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:

            printf("Enter the item:");
            scanf("%d", &p);
            insert(p);
            break;
        case 2:
            printf("Enter the item you want to search: ");
            scanf("%d", &q);
            search(q);
            break;
        case 3:
            printInorder(root);
            break;
        case 4:
            printPreorder(root);
            break;
        case 5:
            printPostorder(root);
            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}
