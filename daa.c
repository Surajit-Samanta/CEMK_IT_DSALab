#include<stdio.h>
int fib(int n);
int i;
int main()
{
	int n;
	printf("\nEnter the number of range: ");
	scanf("%d", &n);
	printf("%d\n",fib(n));
return 0;
}

int fib(int n)
	{
		if (n<=0)
		{
			printf("\nNumber of calls=%d", i++);
			return(1);
		}
		else
		{
			printf("\nNumber of calls =%d", i++);
			return (fib(n-1)+fib(n-2));
		}
	}

