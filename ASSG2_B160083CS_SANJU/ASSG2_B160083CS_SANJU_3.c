#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int left (int i)
{
	return (2*i)+1;
}
int right (int i)
{
	return (2*i)+2;
}
void max_heapify(int *a, int i, int n)
{   
	int temp,largest;
	int l=left(i);
	int r=right(i);
	if ((l<=n) && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if ((r<=n) && a[r]>a[largest])
		largest=r;
	if (largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
        max_heapify(a, largest, n);
    }
}

void build_max_heap(int *a, int k, int n)
{
	int i,temp;
	if (n%2==0)
	    temp=(n/2)-1;
	else
	    temp=n/2;
	for (i=temp; i>=0; i--)
	{
		max_heapify(a,i,n);
	}
	for (i=1;i<k;i++)
	{
	    if (a[0]>a[n+i])
	    {
	    	temp=a[n+i];
	    	a[n+i]=a[0];
	    	a[0]=temp;
	    }
	    max_heapify(a,0,n);
	}
}
 

int main()
{
	int i, n, *arr, k;
	scanf("%d", &n);
	arr=(int *)malloc(n*sizeof(int));
	for (i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d",&k);
	if ((n-k)>=0)
	{
    	build_max_heap(arr,k,n-k);
    	printf("%d ", arr[0]);
    	printf("\n");
	}
	free(arr);
	return 0;
}