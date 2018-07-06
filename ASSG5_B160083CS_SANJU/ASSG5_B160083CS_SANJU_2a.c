#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct List
{
	int key;
	struct List *next;	
};

struct Node
{
	int rank;
	int key;
	struct Node *parent;
}*temp=NULL;

struct Node *array[1000];

int x, y;


void makeset(int x);
struct Node* find(int x);
struct Node* link(struct Node *x, struct Node *y);
struct Node* unify(int x, int y);

int min_weight=0;
struct Edge
{
	int st;
	int end;
	int w;
};

struct List *list = NULL;

int i, j, n, k, u, v;
int count, val, p;
int t1, t2, t3;

int main()
{
	char ch;
	int sum=0, flag=0, st, end;
	scanf("%d",&sum);
	n = sum;
	struct List *adj[n];
	//struct Node1 *array[n];
	struct Edge egde[1000];
	for(i=0; i<n; i++)
	{
		adj[i] = (struct List *)malloc(sizeof(struct List));
		adj[i]->key = i;
		adj[i]->next = NULL; 	
	}
	j=0;
	scanf("%c",&ch);
	scanf("%c",&ch);
	/*
	for (i=0;i<n;i++)
	{
		flag=0;
		a='c';
		while(a!='\n')
		{
			scanf("%c",&a);
			if (a=='\n')
				if (flag==0)
					break;
				else
				{
					//printf("%d",sum);
					newnode(&list[0],sum,i);
					sum=0;	
				}
			else if((isdigit(a)) && (a!=' '))
			{
				num=a-48;
				sum=sum*10+num;
				flag=1;
			}
			else if (a==' ')
			{
				//printf("%d",sum);
				newnode(&list[0],sum,i);
				sum=0;
				flag=1;
			}
		}*/
	while(j<n)
	{	
		if(j!=0)
			scanf("%c",&ch);
		while(ch!='\n')
		{
			while(isdigit(ch))
			{
				sum = 0;
				while(ch!=' ' && ch!='\n')
				{
					sum = sum*10 + (int)ch - 48;
					scanf("%c",&ch);
				}
				if(ch == '\n')
				{
					list = adj[j];
					while(list->next != NULL)
						list = list->next;
					struct List *tp = (struct List*)malloc(sizeof(struct List));
					tp->key = sum;
					tp->next = NULL;
					list->next = tp;
					//	
					break;
				}	
				else
				{
					list = adj[j];
					while(list->next != NULL)
						list = list->next;
					struct List *tp = (struct List*)malloc(sizeof(struct List));
					tp->key = sum;
					tp->next = NULL;
					list->next = tp;
					scanf("%c",&ch);
				}	
			}
		}	
		j++;
	}
	k=0;
	j=0;
	while(k<n)
	{
		list = adj[k];
		u = list->key;
		count = 0;
		list = list->next;
		while(list)
		{
			count++;
			list = list->next;
		}
		list = adj[k]->next;
		for(i=0; i<count; i++)
		{
			scanf("%d", &val);
			v = list->key;
			egde[j].st = u;
			egde[j].end = v;
			egde[j].w = val;
			j++;
			list = list->next;
		}
		k++;
	}
	count = j;
	for(i=0; i<j; i++)
	{
		for(p=i+1;p<j;p++)
		{
			if(egde[i].w > egde[p].w)
			{
				t1 = egde[i].st;
				t2 = egde[i].end;
				t3 = egde[i].w;
				egde[i].st = egde[p].st;
				egde[i].end = egde[p].end;
				egde[i].w = egde[p].w;
				egde[p].st = t1;
				egde[p].end = t2;
				egde[p].w = t3;
			}
		}
	}
	for(x=0; x<n; x++)
	{
		makeset(x);
	}
	for(i=0; i<count; i++)
	{
		u = egde[i].st;
		v = egde[i].end;
		val = egde[i].w;
		if(find(u) != find(v))
		{
			min_weight = min_weight + val;
			unify(u,v);
		}
	}
	printf("%d\n", min_weight);
	return 0;
}

void makeset(int x)
{
	if(array[x]==NULL)
	{
		array[x] = (struct Node *)malloc(sizeof(struct Node));
		array[x]->key = x;
		array[x]->parent = array[x];
		array[x]->rank = 0;
	}	
	else
	{	
		printf("PRESENT\n");
	}
	return;	 
}

struct Node* find(int x)
{	
	int h = x;
	if(array[h] == NULL)
	{
		return NULL;
	}
	if(array[h] == array[h]->parent)
	{
		return array[h];
	}
	else
		find((array[h]->parent)->key);	
}

struct Node* link(struct Node *x, struct Node *y)
{
	if(y->rank > x->rank)
	{
		x->parent = y;
		return y;
	}
	else
	{
		y->parent = x;
		if(x->rank == y->rank)
			x->rank = x->rank + 1;
		return x;	
	}
}

struct Node* unify(int x, int y)
{
	struct Node *m = find(x);
	struct Node *n = find(y);
	if(m == NULL || n == NULL)
	{
		return NULL;
	}
	else
	{
		temp = NULL;
		temp = link(m, n);
		return temp;
	}
}
