#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int size;

struct data
{
	int key;
	//int data;
	struct data* next;
};

int prime(int n);
int find_index(int key, int i, int c);
struct data* hashTable(int m);
void insert(struct data* h, int key, int c);
//struct data hash[500];
void search(struct data* h, int key, int c);
void print(struct data* h, int c);
void delete(struct data* h, int key, int c);
void makenew(struct data* h);
void main()
{
	char ch1,ch2;
	int c,k,m;
	scanf("%c",&ch1);
	switch(ch1)
	{
		case'a':
			c=1;
			break;
		case 'b':
			c=2;
			break;
		case 'c':
			c=3;
			break;
		case 'd':
			c=4;
			break;
		default:
			break;
	}
	scanf("%d", &m);
	size=m;
	struct data* hash=hashTable(m);
	makenew(&hash[0]);
	while(1)
	{
		scanf("%c",&ch2);
		switch(ch2)
		{
			case'i':
				scanf("%d",&k);
				insert(hash,k,c);
				break;
			case 's':
				scanf("%d",&k);
				search(hash,k,c);
				break;
			case 'd':
				scanf("%d",&k);
				delete(hash,k,c);
				break;
			case 'p':
				print(hash,c);
				break;
			case 't':
				exit(1);
			default:
				break;
		}
	}
}

int prime(int n)
{
	int j,i,p;
	for(i=2; i<n; i++)
	{
		for(j=2; j<i; j++)
		{
			if (i%j==0)
				break;
			p=i;
		}
	}
	return p;
}

int find_index(int key, int i, int c)
{	
	int index;
	if (c==1)
	{
		index=((key%size)+i)%size;
	}
	else if (c==2)
	{
		index=((key%size)+(i*i))%size;
	}
	else if (c==3)
	{
		int r=prime(size);
		index=((key%size)+(i*(r-(key%r))))%size;
	}
	else
	{
		index=key%size;
	}
	return index;
}

struct data* hashTable(int m)
{
	struct data* hash;
	hash=(struct data*)malloc(m*sizeof(struct data));
	return hash;
}

void insert(struct data* h, int key, int c)
{	
	int j,i=0;
	while(i<size)
	{
		j=find_index(key, i, c);
		if (h[j].key==-1)
		{		
			h[j].key=key;
			return;
		}
		else if(c==4)
		{
			struct data* new=(struct data*)malloc(sizeof(struct data));
			struct data* next1=h[j].next;
			new->key=key;
			new->next=NULL;
			if (next1==NULL)
			{
				h[j].next=new;
				//printf("1");
				return;
			}
			while(next1->next!=NULL)
				next1=next1->next;
			next1->next=new;
			//printf("2");
			return;
		}
		else
				i++;
	}
	printf("ERROR\n");

}
	
void search(struct data* h, int key, int c)
{	int j,i=0;
	while(i<size)
	{
		j=find_index(key, i, c);
		//if (h[j].key==-1)
			//break;
		if (h[j].key==key)
		{		
			printf("1 \n");
			return;
		}
		else if(c==4)
		{
			struct data* next1=h[j].next;
			while(next1!=NULL)
			{
				if(next1->key==key)
				{
					printf("1 \n");
					return;
				}
				next1=next1->next;
			}
			printf("-1 \n");
			return;
			//next1->next=new;
		}
		else
				i++;
	}
	printf("-1 \n");

}

void delete(struct data* h, int key, int c)
{	int j,i=0;
	while(i<size)
	{
		j=find_index(key, i, c);
		//if (h[j].key==-1)
			//break;
		if (h[j].key==key)
		{		
			h[j].key=-1;
			return;
		}
		else if(c==4)
		{
			struct data* prev=h;
			struct data* next1=h[j].next;
			while(next1!=NULL)
			{
				if(next1->key==key)
				{
					prev->next=next1->next;
					return;
				}
				prev=next1;
				next1=next1->next;
			}
		}
		else
				i++;
	}

}

void makenew(struct data *h)
{
	//struct data current=*h;
	int i=0;
	for(i=0;i<size;i++)
	{
		h[i].key=-1;
		h[i].next=NULL;
	}
}

void print(struct data* h, int c)
{
	int i;
	for(i=0; i<size;i++)
	{
		if (h[i].key==-1)
		{
			printf("%d ()\n",i);
		}
		else if(c==4)
		{
			printf("%d (%d ", i,h[i].key);
			struct data* next1=h[i].next;
			if (next1==NULL)
			{
				printf(")\n");
				continue;
			}
			while (next1->next!=NULL)
			{
				printf("%d ",next1->key);
				next1=next1->next;
			}
			printf("%d)\n",next1->key);
		}
		else
			printf("%d (%d)\n",i,h[i].key);
	}
}