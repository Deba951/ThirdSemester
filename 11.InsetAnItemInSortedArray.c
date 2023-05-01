#include<stdio.h>

int main()
{
    int n,arr[100],i;
    printf("\nEnter The Array Limit : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",arr+i);
    }
    int k;
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&k);
    for(i=n-1 ; i>=0 && arr[i]>k ; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[i+1]=k;
    printf("\nThe Sorted Array is : ");
    for (i = 0; i < n+1; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
