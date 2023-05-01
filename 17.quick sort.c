#include <stdio.h>

void printArray(int *a, int n)
{
	int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j]= temp;
    return j;
}

void quickSort(int a[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(a, low, high); 
        quickSort(a, low, partitionIndex - 1); 
        quickSort(a, partitionIndex + 1, high);
    }
}

int main()
{
    
    int a[20],i,n;
    printf("ENTER THE SIZE:\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printArray(a, n);
    quickSort(a, 0, n - 1);
    printArray(a, n);
    return 0;
}
