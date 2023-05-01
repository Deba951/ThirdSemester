#include <stdio.h>
#include <stdlib.h>
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n%d ", arr[i]);
    }
    printf("\n");
}
void update(int arr[], int n, int x, int k)
{
    int i;
    if (k > 0 && k < n)
    {
        for (i = 0; i < n; i++)
        {
            arr[k] = x;
        }
    }
    else
    {
        printf("\nInvalid choice\n");
    }
}
int insert(int arr[], int n, int x, int k)
{
    int i;
    if (k < 1 || k > n)
    {
        printf("\nNot possible\n");
        return -1;
    }
    for (i = n; i >= k; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[k - 1] = x;
    n = n + 1;
    for (i = 0; i < n; i++)
    {
        printf("\n%d ", arr[i]);
    }
    return n;
}
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return 1;
            break;
        }
    }
    return 0;
}
void Remove(int arr[], int n, int x)
{
    int i, k;
    for (k = 0; k < n; k++)
    {
        if (arr[k] == x)
            break;
    }
    if (k < n)
    {
        printf("\nDeleted Array is: ");
        for (i = k; i <= n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n = n - 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int size;
    printf("Enter the size of the Array: ");
    scanf("%d", &size);
    int arr[size];
    int i;
    printf("\nEnter the elements of the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    int ch;
	while(1)
	{
		printf("\n1: INSERT\n");
		printf("2: REMOVE\n");
		printf("3: DISPLAY\n");
		printf("4: UPDATE\n");
		printf("5: SEARCH\n");
		printf("6: EXIT\n");
		printf("Enter your choice: \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element and position\n");
        		int e, p;
        		scanf("%d %d", &e, &p);
        		insert(arr, size, e, p);
        		break;
        	case 2:
        		printf("\nEnter the element\n");
        		int e2;
        		scanf("%d", &e2);
        		Remove(arr, size, e2);
        		break;
        	case 3:
        		display(arr, size);
        		break;
			case 4:
				printf("\nEnter the element and position\n");
        		int element, position;
        		scanf("%d %d", &element, &position);
        		update(arr, size, element, position);
        		display(arr, size);
        		break;
			case 5:
        		printf("\nEnter the element\n");
        		int e1;
        		scanf("%d", &e1);
        		int s = search(arr, size, e1);
        		if (s == 1)
        		{
            		printf("\nElement %d is present in the array", e1);
        		}
        		else
        		{
            		printf("\nElement %d is not present in the array", e1);
        		}
        		break;
			default:
				exit(1);
		}
	}
}