#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    int weight;
    struct Node *next;
};

struct table
{
    struct Node *list;
}adjl[10000];

int queue[10000],color[10000],dist[10000],heap[10000];
int n,v,rear=-1,front=0,heapsize=-1;

void min_heapify(int i);

int parent(int i);

void enqueue(int x);

int dequeue();

void dijkstra(int v);

int main()
{
    int i,j;
    int sum,num,t,d;
    char ele,c,ch[4];
    scanf("%d",&n);
    scanf("%c",&c);
    for( i=0;i<n;i++)
    {
        color[i]=0;
    }
    for(j=0;j<n;j++)
    {
        adjl[j].list=NULL;
        while(1)
        {
            scanf("%c",&c);
            if(c=='\n')
                break;
            else
            {
                sum=c-'0';
                while(1)
                {
                    scanf("%c",&ele);
                    if(ele=='\n' || ele==' ')
                        break;
                    num=ele-'0';
                    sum=sum*10 +num;        
                }
            }
            struct Node *newnode=malloc(sizeof(struct Node));
            newnode->data=sum;
            newnode->weight=0;
            newnode->next=NULL;
            if( adjl[j].list==NULL)
            {
                adjl[j].list=newnode;
            }
            else
            {
                struct Node *temp=adjl[j].list;
                while(temp->next!=NULL)
                temp=temp->next;
                temp->next=newnode;
            }
            if(ele=='\n')
                break;
        }
    }
    for(j=0;j<n;j++)
    {
        struct Node*temp=adjl[j].list;
        while(1)
        {
            scanf("%c",&c);
            if(c=='\n')
                break;
            else
            {
                sum=c-'0';
                while(1)
                {
                    scanf("%c",&ele);
                    if(ele=='\n' || ele==' ') 
                        break;
                    num=ele-'0';
                    sum=sum*10 +num;
                }
            }
            temp->weight=sum;
            temp=temp->next;
            if(ele=='\n')
                break;
        }
    }
    while(1)
    {
    scanf("%s",ch);
    if(strcmp(ch,"apsp")==0)
    {
        scanf("%d",&t);
        dijkstra(t);
        for(i=0;i<n;i++)
        {
            if(dist[i]==10001)
                printf("INF ");
            else
                printf("%d ",dist[i]);
        }
        printf("\n");
        for(i=0;i<n;i++)
        color[i]=0;
    }
    else if(strcmp(ch,"sssp")==0)
    {
        scanf("%d%d",&t,&d);
        dijkstra(t);
        if(dist[d]==10001)
            printf("UNREACHABLE\n");
        else
            printf("%d\n",dist[d]);
        for(i=0;i<n;i++)
            color[i]=0;
    }
    else if(strcmp(ch,"stop")==0)
        exit(1);
    }
    return 0;
}

void dijkstra(int v)
{
    int i;
    dist[v]=0;
    enqueue(v);
    //color[v]=1;
    for(i=0;i<n;i++)
    {    
        if(i!=v)
            dist[i]=10001;
    }
    while(rear!=-1)
    {
        v=dequeue();
        color[v]=1;
        struct Node *temp=adjl[v].list;
        while(temp!=NULL)
        {
           
            if(color[temp->data]==0)
            {
                int x=dist[v]+temp->weight;
                if(x<dist[temp->data])
                    dist[temp->data]=x;
                enqueue(temp->data);
            }
            temp=temp->next;
        }
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

int parent(int i)
{
    if((i%2)==0)
        return (i-2)/2;
    else 
        return (i-1)/2;
}

void min_heapify(int i)
{
    int min=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<=rear && dist[queue[left]]<dist[queue[min]])
        min=left;
    if(right<=rear && dist[queue[right]]<dist[queue[min]])
        min=right;
    if(min!=i)
    {
        int temp=queue[i];
        queue[i]=queue[min];
        queue[min]=temp;
        min_heapify(min);
    }
}

int extract_min()
{   int temp=heap[0];
    heap[0]=heap[heapsize];
    heapsize--;
    min_heapify(0);
    return temp;
}