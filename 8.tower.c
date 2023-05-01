#include<stdio.h>
#include<math.h>
void toh(int n,char s,char d,char t)
{
	if(n==1)
		printf("move disk from %c to %c",s,d);
	else if(n>1)
	{
		toh(n-1,s,t,d);
		printf("\nmove disk from %c to %c\n",s,d);
		toh(n-1,t,d,s);
	}
}
int main()
{
	int n;
	printf("enter number of disk:");
	scanf("%d",&n);
	toh(n,'s','d','t');
	printf("\nNo. of moves is %d",(int)pow(2,n)-1);
}
