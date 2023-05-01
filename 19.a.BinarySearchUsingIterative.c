#include<stdio.h>
int iterativeBinarySearch(int array[],int start_index,int end_index,int element)
{
	while(start_index<=end_index)
	{
		int middle=start_index+(end_index-start_index)/2;
		if(array[middle]==element)
			return middle;
		if(array[middle]<element)
			start_index=middle+1;
		else
			end_index=middle-1;
	}
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
    int found_index;
    found_index=iterativeBinarySearch(a,0,n-1,x);
    if(found_index==-1)
    	printf("The item is not found..");
    else
    	printf("The item is found at position %d",found_index);
	return 0;
}
