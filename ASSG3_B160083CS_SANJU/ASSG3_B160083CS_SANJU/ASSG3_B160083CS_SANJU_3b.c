#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int n;
//int rear=0;
//int front=0;

struct Node
{
	long int data;
	//struct Node *head;
	struct Node *next;
};

struct list
{
	struct Node *front;
	struct Node *rear;
};


void print_queue(struct list *l)
{
	if ((l->rear)==NULL)
		printf("-1\n");
	else
	{
		struct Node *h=(struct Node *)malloc(sizeof(struct Node));
		h=l->front;
		while(h!=NULL)
		{
			printf("%ld ",h->data);
			h=h->next;
		}
		printf("\n");
	}
}

void enqueue(struct list *l,long int m)
{
	struct Node *h=(struct Node *)malloc(sizeof(struct Node));
	h->next=NULL;
	h->data=m;
	if ((l->rear)==NULL)
	{
		l->front=h;
		l->rear=h;
	}
	else
	{
		l->rear->next=h;
		l->rear=h;
	}
}

void dequeue(struct list *l)
{
	if (l->front==NULL)
	{
		l->rear=NULL;
		printf("-1\n");
	}
	else
	{
		printf("%ld\n", l->front->data);
		l->front=l->front->next;
		if (l->front==NULL)
			l->rear=NULL;
	}
}

void main()
{	
    char c;
	long int m;
	struct list *l = (struct list*)malloc(sizeof(struct list));
	l->front=l->rear=NULL;
	while(1)
	{
	    scanf("%c",&c);
	    if(c=='e')
	    {
		    scanf("%ld",&m);
		    enqueue(l,m);
	    }
	    if(c=='d')
		    dequeue(l);
	    if(c=='p')
		    print_queue(l);
	    if(c=='s')
		    break;
    }
}