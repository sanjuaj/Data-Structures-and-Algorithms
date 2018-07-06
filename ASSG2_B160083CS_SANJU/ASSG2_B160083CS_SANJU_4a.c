#include<stdio.h>
#include<stdlib.h>

int find(int **a, int i, int j, int e, int r, int c)
{
	while(i<r)
	{
		while(j>=0)
		{
			if (a[i][j]==e)
				return 1;
			else if (a[i][j]>e)
				return find(a, i,j-1,e,r,c);
			else 
				return find(a,i+1,j,e,r,c);
		}
		return -1;
	}
	return -1;
}

int main()
{
	int i, j, r, c, k, flag=0;
	scanf("%d %d",&r, &c);
	int **arr=(int **)malloc(r*sizeof(int *));

	for (i=0; i<r; i++)
	{
		arr[i]=(int *)malloc(c*sizeof(int));
	}
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d ",&arr[i][j]);
		}
	}

	scanf("%d", &k);
	int check=find(arr,0,c-1,k, r, c);
	printf("%d",check);
}

