#include<stdio.h>
#define INF 999

int m[20][20], s[20][20];

void optimal_paren(int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		optimal_paren(i,s[i][j]);
		optimal_paren(s[i][j]+1,j);
		printf(")");
	}
}

void matrix_chain(int p[],int n)
{
	int i,l,j,k,q;
	for(i=0;i<n;i++)
		m[i][i]=0;
	for(l=1;l<n;l++)
	{
		for(i=1;i<n;i++)
		{
			j=i+l;
			m[i][j]=INF;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+i][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}

void main()
{
   	int i,n,p[10];
   	printf("enter the number of matrix= ");
   	scanf("%d",&n);
   	printf("enter diagonal values= ");
   	for(i=0;i<=n;i++)
   		scanf("%d",&p[i]);
   	matrix_chain(p,n);
   	printf("minimum number of multiplication is = %d \n",m[1][n]);
   	printf("the expression is= ");
   	optimal_paren(1,n);
}

