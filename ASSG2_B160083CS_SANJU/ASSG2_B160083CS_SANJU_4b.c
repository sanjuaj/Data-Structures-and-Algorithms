#include<stdio.h>
#include<stdlib.h>

/*int binary(int *a, int e, int b, int l, int f)
{
	while(b<=l)
	{
		int mid =(b+l)/2;
		if (a[mid]==e)
			f=1;
			return mid;
		else if (a[mid]>e)
			l=mid-1;
		else if (a[mid]<e)
			b=mid+1;
	}
	if (f==0)
		printf("-1");
}*/

void mod_binary(int *a, int e, int b, int l, int f)
{
	
	while(l>=b)
	{
		int mid=(l+b)/2;
		if (a[mid]==e)
		{
			f=1;
			printf("%d",mid);
			break;
		}

		if (a[b]<=a[mid-1])
		{	
			if (e>=a[b] && e<=a[mid-1])
				l=mid-1;
			else
				b=mid+1;
		}
		else if (a[mid+1]<=a[l])
		{
			if (e>=a[mid+1] && e<=a[l])
				b=mid+1;
			else
				l=mid-1;
		}
		else
			break;
	}
	if (f!=1)
		printf("-1");
}

int main()
{
	int n, *arr, i, ele;
	scanf("%d", &n);
	arr=(int *)malloc(n*sizeof(int));
	for( i=0; i<n ; i++ )
	{
		scanf("%d ", &arr[i]);
	}
	scanf("%d", &ele);
	mod_binary(arr, ele, 0, n-1, 0);
}