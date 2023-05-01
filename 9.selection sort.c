#include <stdio.h>
void swap(int arr[],int i, int min)
{
	int temp=arr[i];
	arr[i]=arr[min];
	arr[min]=temp;
}
void selectionsort(int arr[],int n)
{
	int i,j,min,k,m=1;
	for(i=0;i<=n-2;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
			min=j;
		}
		swap(arr,i,min);
		printf("pass:%d\n",m);
		for(k=0;k<n;k++)
			printf("%d  ",arr[k]);
			
			printf("\n");
			m++;
	}
	printf("sorting array elements:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("the array before sorting: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	selectionsort(arr,n);
	return 0;
}
