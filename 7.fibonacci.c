#include<stdio.h>
int fib (int n,int a,int b)
{
	if(n==0)
		return a;
	else if(n==1)
		return b;
	else
		return fib(n-1,b,a+b);
}
int main()
{
	int n;
	printf("Enter the value of n :");
	scanf("%d",&n);
	printf("\n fibonacci series is %d",fib(n-1,0,1));
	return 0;
}
