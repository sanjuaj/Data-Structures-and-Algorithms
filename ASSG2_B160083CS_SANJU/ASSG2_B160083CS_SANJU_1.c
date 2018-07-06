#include<stdio.h>
#include<stdlib.h>
void merge (int *a, int p, int mid1, int mid2, int r)
{
	int i,j,k;
	int n1=mid1-p+1;
	int n2=mid2-mid1;
	int n3=r-mid2;
	int l[50],m[50],g[50];
	for (i=0;i<n1;i++)
	{
		l[i]=a[p+i];
	}
	for (j=0;j<n2;j++)
	{
		m[j]=a[mid1+j+1];
	}
	for (k=0;k<n3;k++)
	{
		g[k]=a[mid2+k+1];
	}
	l[i]=100000000;
	m[j]=100000000;
	g[k]=100000000;
	i=0;
	j=0;
	k=0;
	for (int n=p;n<=r;n++)
	{
		if ((l[i]<=m[j]) && (l[i]<=g[k]))
		{
			a[n]=l[i];
			i++;
		}
		else if ((m[j]<=l[i]) && (m[j]<=g[k]))
		{
			a[n]=m[j];
			j++;
		}
		else
		{
			a[n]=g[k];
			k++;
		}
	}
}

void mergesort(int *a, int p ,int r)
{
	if (p<r)
	{
		int temp=(((r-p)-((r-p)%3))/3)+1;
		int mid1=(p+temp-1);	
		int mid2=mid1+temp;
		mergesort(a, p, mid1);
		mergesort(a, mid1+1, mid2);
		mergesort(a, mid2+1, r);
		merge(a,p,mid1,mid2,r);
	}
}
		
int main()
{
	FILE *fi, *fo;

	char ch;
	int *arr, i, len;
	arr=(int *)malloc(10000000*(sizeof(int)));
	fi=fopen("in", "rb");
	fo=fopen("out","wb");
	if (!fi)
	{	
		printf("The file is not loaded properly");
		return 0;
	}
	/*if (!fo)
	{	
		printf("The file is not loaded properly");
		return 0;
	}*/
	
	i=0;
	while (!feof(fi))
	{
		fscanf(fi,"%d ",&arr[i]);
		i++;
	}
	arr=(int *)realloc(arr,i*sizeof(int));
	len=i;
	mergesort(arr,0,len-1);
	for (i=0; i<len; i++)
		fprintf (fo,"%d ",arr[i]);
	fclose(fi);
	fclose(fo);
	return 0;
}
