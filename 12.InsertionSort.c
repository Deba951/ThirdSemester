#include <stdio.h>

void printArray(int array[], int size) 
{
	int i;
  for ( i = 0; i < size; i++) 
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) 
{
	int step, key, j;
  for ( step = 1; step < size; step++)
   {
     key = array[step];
     j = step - 1;


    while (key < array[j] && j >= 0) 
	{
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}


int main() {
   int n,arr[100],i;
    printf("\nEnter The Array Limit : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",arr+i);
    }
  insertionSort(arr, n);
  printf("Sorted array in ascending order:\n");
  printArray(arr,n);
}
