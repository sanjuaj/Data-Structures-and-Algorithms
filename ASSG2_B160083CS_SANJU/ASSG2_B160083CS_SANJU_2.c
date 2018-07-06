#include<stdio.h>
#include<stdlib.h>

int partition(int *a,int p,int r)
{
    int x=a[r];
    int i=p-1,j,temp;
    
    for(j=p;j<=r-1;j++)
    {   
        if(a[j]<=x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
         
    }
    temp=a[i+1];
    a[i+1]=a[j];
    a[j]=temp; 
    return i+1;
}

int get_median(int *a,int p,int r,int med)
{        
    int pivot=partition(a,p,r);
    if(pivot==med)
        return med;
    if(pivot>med)
        get_median(a,p,pivot-1,med);
    else 
        get_median(a,pivot+1,r,med);
}

void quicksort(int *a,int p,int r,int ctr)
{
    int q,med,n;
    n=r-p+1;
    if(n%2==0)
        med=p+(n/2)-1;
    else 
        med=p+(n/2);

    if(p<r)
    {
    q=get_median(a,p,r,med);
    if(ctr<2)
        printf("%ld\n",a[q]);
    quicksort(a,p,q-1,ctr+1);
    quicksort(a,q+1,r,ctr+1);
    }
}

int main()
{
  int n,i,ctr=0;
  scanf("%ld",&n);
  int a[n];
  for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    quicksort(a,0,n-1,0);
    for(i=0;i<n;i++)
    {
        printf("%ld ",a[i]);
    }
    return 0;
}






