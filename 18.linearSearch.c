#include<stdio.h>
int linearsearch(int arr[],int n, int x)
{
	int i;
	for(i=0;i<n;i++)
		if(arr[i]==x)
			return i;
	return -1;
}
int main()
{
	int a[20],i,x,n;
    printf("Enter the range: ");
    scanf("%d",&n);
     
    printf("Enter the elements of the array: ");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
     
    printf("Enter element to search:");
    scanf("%d",&x);
    int result;
    result=linearsearch(a,n,x);
    if(result==-1)
    	printf("The item is not found..");
    else
    	printf("The item is found at position %d",result+1);
	return 0;
}
