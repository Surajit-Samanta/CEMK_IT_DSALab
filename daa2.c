#include<stdio.h>

int fib(int n, int a[])
{
	if (a[n]!=-1){
	return a[n];
	}

	if (n<=1)
	{
		a[n]=n;
	}
	else
	{
		a[n]=fib(n-1,a)+fib(n-2,a);
	}
	return a[n];
}

int main()
{
	int n,i;
	printf("Enter the number of term in the Fibonacci sequence: ");
	scanf("%d",&n);

	int a[n+1];
	for(i=0;i<=n;i++)
	{
		a[i]=-1;
	}

	printf("Fibonacci sequence: ");
	for(i=0;i<n;i++)
	{
		printf("%d\n",fib(i,a));
	}
	return 0;
}
