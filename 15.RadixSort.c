#include <stdio.h>

int getMax(int a[], int n)
{
  	int max = a[0],i;
  	for (i = 1; i < n; i++)
    if (a[i] > max)
    	max = a[i];
  	return max;
}
void countingSort(int a[], int size, int place) {
	int output[size + 1];
  	int max = (a[0] / place) % 10;
	int i;
  	for (i = 1; i < size; i++)
	{
    if (((a[i] / place) % 10) > max)
      max = a[i];
    }
  	int count[max + 1];

  	for (i = 0; i < max; ++i)
    	count[i] = 0;
    
	for (i = 0; i < size; i++)
    	count[(a[i] / place) % 10]++;
    	
    for (i = 1; i < 10; i++)
    	count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
	{
    	output[count[(a[i] / place) % 10] - 1] = a[i];
    	count[(a[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
    	a[i] = output[i];
}
void radixsort(int a[], int size) {
	int place;
	int max = getMax(a, size);
	for (place = 1; max / place > 0; place *= 10)
    	countingSort(a, size, place);
}

void printArray(int a[], int size) {
	int i;
  for (i = 0; i < size; ++i) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}

int main() {
	int n,i;
    printf("Enter your size of the array= ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in the array(only positive):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    radixsort(a, n);
  	printArray(a, n);
	return 0;
}
