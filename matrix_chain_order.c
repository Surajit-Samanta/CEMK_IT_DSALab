#include<stdio.h>

int n;
void matrix_chain(int p[]);

int main()
{
	int i;
	int p[50];
	printf("\n Enter the size of chain\n");
	scanf("%d",&n);
	printf("Enter the value of the chain\n");
	for(i=0;i<=n;i++)
	{
		scanf("%d", &p[i]);
	}
	matrix_chain(p);
	return 0;
}

void matrix_chain(int p[])
{
	int i,j,l,k;
	int m[n][n],s[n][n];
	for(i=1; i<=n; i++)
	{
		m[i][i]=0;
	}
	for(l=2; l<=n; l++)
	{
		for(i=1; i<=n-1; i++)
		{
			j=i+l-1;
			m[i][j]=99999;
			for(k=i; k<=j-1; k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i+1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("\n The m matrix is \n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("\n The s matix is \n");

		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				printf("%d/t",s[i][j]);
			}
			printf("\n");
		}

}
