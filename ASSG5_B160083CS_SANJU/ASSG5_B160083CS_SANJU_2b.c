#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int n,dest,sum=0,rear,front,queue[1000];
int dist[1000],color[1000],heap[1000];

struct Node
{
	int data,weight;
	struct Node *next;
};

struct table
{
    struct Node *list;
}vertex_set[1000];

int heapsize=-1;
void min_heapify(int i);
int extract_min();
int parent(int x);
void prim();
void heap_insert(int i);
void insert_edge(int i,int x);


int main()
{
int i,j;
int sum,num;
int t,d;
char ele,c;
  scanf("%d",&n);
  scanf("%c",&c);
for( i=0;i<n;i++)
 {
     color[i]=0;
 }
for(j=0;j<n;j++)
   {
      vertex_set[j].list=NULL;
      while(1)
     {
        scanf("%c",&c);
        if(c=='\n')break;
        else
        {
            sum=c-'0';
            while(1)
            {
                scanf("%c",&ele);
                if(ele=='\n' || ele==' ' ) break;
                num=ele-'0';
                sum=sum*10 +num;
                
            }
        }
       
        struct Node *newnode=malloc(sizeof(struct Node));
        newnode->data=sum;
        newnode->weight=0;
        newnode->next=NULL;
        if( vertex_set[j].list==NULL)
        {
            vertex_set[j].list=newnode;
        }
        else
        {
            struct Node *temp=vertex_set[j].list;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
        }
        if(ele=='\n') break;
        
    }
  }
  
  for(j=0;j<n;j++)
   {
       struct Node*temp=vertex_set[j].list;
      while(1)
     {
        scanf("%c",&c);
        if(c=='\n')break;
        else
        {
            sum=c-'0';
            while(1)
            {
                scanf("%c",&ele);
                if(ele=='\n' || ele==' ' ) break;
                num=ele-'0';
                sum=sum*10 +num;
                
            }
        }
        temp->weight=sum;
        temp=temp->next;
        if(ele=='\n') break;
        
    }
  }
	prim();  
	sum=0;
	for(i=0;i<n;i++)
		sum+=dist[i];
	printf("%d\n",sum);
  return 0;
}

void insert_edge(int i,int x)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->weight=0;
	temp->next=NULL;

	if(vertex_set[i].list==NULL)
	{	vertex_set[i].list=temp;
		return;
	}
	struct Node *temp2=vertex_set[i].list,*prev=NULL;
	
	while(temp2!=NULL)
	{	prev=temp2;
		temp2=temp2->next;
	}
	
	prev->next=temp2;
}


void heap_insert(int i)
{
	heapsize++;
	heap[heapsize]=i;
	i=heapsize;
	while(i>0 && dist[heap[parent(i)]]>dist[heap[i]])
	{       int swap=heap[parent(i)];
	        heap[parent(i)]=heap[i];
	        heap[i]=swap;
	        i=parent(i);

	}
}


void min_heapify(int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int min;

	if(l<=heapsize && dist[heap[l]] < dist[heap[i]])
		min=l;
	else min=i;

	if(r<=heapsize && dist[heap[r]] < dist[heap[min]] )
		min=r;

	if(min!=i)
	{
		int temp=heap[min];
		heap[min]=heap[i];
		heap[i]=temp;
		min_heapify(min);
	}
}

void enqueue(int x)
{
    rear++;
    queue[rear]=x;//
    int i=rear;
    while(i>0 && dist[queue[parent(i)]]>dist[queue[i]])
    {
        int temp=queue[parent(i)];
        queue[parent(i)]=queue[i];
        queue[i]=temp;
        i=parent(i);
    }
}

int dequeue()
{
    int x=queue[0];
    queue[0]=queue[rear];
    rear--;
    min_heapify(0);
    return x;
}

int extract_min()
{	int temp=heap[0];
	heap[0]=heap[heapsize];
	heapsize--;
	min_heapify(0);
	return temp;
}

int parent(int x)
{
	if(x%2==0)
		return (x-2)/2;
	else
		return (x-1)/2;
}

void prim()
{
	int i;
	for(i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
		color[i]=0;	
	}

	dist[0]=0;

	heap_insert(0);

	while(heapsize!=-1)
	{
		int u=extract_min();

		color[u]=1;
		struct Node *temp=vertex_set[u].list;
		while(temp!=NULL)
		{

			if(color[temp->data]==0)
			{   
				int t=temp->weight;
				if(t < dist[temp->data])
            				{dist[temp->data]=t;
			}
            heap_insert(temp->data);
			}	
			temp=temp->next;	
		}

	
	}

}