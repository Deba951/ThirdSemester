#include<stdio.h>
void CountSort(int[], int, int);
int main()
{
    int n,i;
    printf("Enter your size of the array= ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in the array(only positive):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int k = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] > k)
      		k = a[i];
    }
    CountSort(a, n, k);
    printf("Your Sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

void CountSort(int a[], int n, int k)
{
    int count[k + 1], b[n],i;

    for (i = 0; i < k + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    for (i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        count[a[i]]--;
        b[count[a[i]]] = a[i];
    }

    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
