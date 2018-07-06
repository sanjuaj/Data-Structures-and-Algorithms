#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

long int heapsize=0;

struct Node
{
	long int key;
	long int pr;
	//struct Node *next;
};

struct Node *ele;
/*struct Queue
{
	struct Node *arr;
	struct Node *front;
	struct Node *rear;
};*/
long int parent(long int i)
{	
	if (i%2==0)
	    return (i/2)-1;
	else
	    return (i/2);
}

long int left (long int i)
{
	return (2*i)+1;
}
long int right (long int i)
{
	return (2*i)+2;
}
void min_heapify(long int i)
{   
	struct Node *tempptr;
	long int smallest,temp,prior;
	long int l=left(i);
	long int r=right(i);

	if ((l<=heapsize) && ele[l].pr<ele[i].pr)
		smallest=l;
	else
		smallest=i;
	if ((r<=heapsize) && ele[r].pr<ele[smallest].pr)
		smallest=r;
	if (smallest!=i)
	{
        temp=ele[smallest].key;
        prior=ele[smallest].pr;
        ele[smallest].key=ele[i].key;
        ele[smallest].pr=ele[i].pr;
        ele[i].key=temp;
        ele[i].pr=prior;
        min_heapify(smallest);
    }
}

void decrease_priority(long int key, long int data)
{
	long int i, temp, prior;
	struct Node *tempptr;
	for(i=0;i<heapsize;i++)
	{
		if (ele[i].key==key)
			break;
	}
	if (ele[i].pr<=data)
	{
		printf("ERROR\n");
	}
	else
	{
		ele[i].pr=data;
		while(i>0 && ele[parent(i)].pr>ele[i].pr)
		{
        	temp=ele[parent(i)].key;
        	prior=ele[parent(i)].pr;
        	ele[parent(i)].key=ele[i].key;
        	ele[parent(i)].pr=ele[i].pr;
        	ele[i].key=temp;
        	ele[i].pr=prior;
        	i=parent(i);
		}
	}
}

void get_min()
{
	if (heapsize==0)
		printf("EMPTY\n");
	else
		printf("%ld (%ld)\n",ele[0].key,ele[0].pr);
}

void extract_min()
{
	if (heapsize==0)
		printf("EMPTY\n");
	else
	{
		printf("%ld (%ld)\n",ele[0].key,ele[0].pr);
    	ele[0]=ele[heapsize];
      	heapsize--;
      	min_heapify(0);
	}
}

void insert(long int data, long int pr)
{
	long int i,temp,prior;
	struct Node *tempptr;
	if(heapsize==0)
	    ele=(struct Node *)malloc(1*sizeof(struct Node));
	else
	    ele=(struct Node *)realloc(ele,(heapsize+1)*sizeof(struct Node));
	ele[heapsize].key=data;
	ele[heapsize].pr=pr;
	i=heapsize;
	while(i>0 && ele[parent(i)].pr>ele[i].pr)
	{
	  	temp=ele[parent(i)].key;
       	prior=ele[parent(i)].pr;
       	ele[parent(i)].key=ele[i].key;
       	ele[parent(i)].pr=ele[i].pr;
       	ele[i].key=temp;
       	ele[i].pr=prior;
	}
	heapsize++;
}
void build_min_heap(long int *a, long int n)
{
	long int i,temp;
	if (n%2==0)
	    temp=(n/2)-1;
	else
	    temp=(n/2)-1;
	for (i=temp; i>=0; i--)
	{
		min_heapify(i);
	}
}

 int main()
{
	//int i, n=0, *arr;
	//struct Node *arr;
	//arr=(int *)malloc(sizeof(int));
	char c;
	long int m, pr;
	//struct Queue *l = (struct Queue*)malloc(sizeof(struct Queue));
	//l->front=l->rear=NULL;
	while(1)
	{
	    scanf("%c",&c);
	    fflush(stdin);
	    if(c=='a')
	    {
		    scanf("%ld %ld",&m, &pr);
		    fflush(stdin);
		    //arr[n-1]=pr;
		    insert(m,pr);
	    }
	    if(c=='g')
		    get_min();
	    if(c=='d')
	    {
	    	scanf("%ld %ld",&m, &pr);
		    fflush(stdin);
		    decrease_priority(m,pr);
	    }
	    if(c=='e')
	    {
		    extract_min();
	    }
	    if(c=='s')
		    break;
    }
	return 0;
}