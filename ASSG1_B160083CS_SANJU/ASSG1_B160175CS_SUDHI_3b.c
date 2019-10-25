#include<stdio.h>
#include<stdlib.h>
void transpose(int n, int **m, int x, int y)
{
	int temp;
	if(x<=n-2)
	{
		if(y<=n-1)
		{	
			temp = m[x][y];
			m[x][y] = m[y][x];
			m[y][x] = temp;
			transpose(n,m,x,y+1);
		}
		else
		{
			++x;
			transpose(n,m,x,x+1);
		}
	}
}
void spiral(int n, int **m)
{
	int i=0,j=0;
	int a=0,b=0,c=0,d=0;
	while(a<=n-2)
	{
		while(j<n-a-1)
		{
			printf("%d ", m[i][j]);
			j++;
		}
		a++;
		while(i<n-b-1)
		{
			printf("%d ", m[i][j]);
			i++;
		}
		b++;
		while(j>c)
		{
			printf("%d ", m[i][j]);
			j--;
		}
		c++;
		while(i>d)
		{
			printf("%d ", m[i][j]);
			i--;
		}
		d++;
		i++;
		j++;	
	}
	if(n%2!=0)
	{
	    printf("%d", m[((n+1)/2)-1][((n+1)/2)-1]);
	}		
} 			
int main()
{
	int n,a,b;
	int **m;
	scanf("%d", &n);
	m = (int **)malloc(n*sizeof(int *));
	for(a=0;a<n;a++)
		m[a] = (int *)malloc(n*sizeof(int));
	for(a=0;a<n;a++)
	{
		for(b=0;b<n;b++)
		{
			scanf("%d",&m[a][b]);
		}
	}
	transpose(n,m,0,1);
	spiral(n,m);
	free(m); 
	return 0;
}

