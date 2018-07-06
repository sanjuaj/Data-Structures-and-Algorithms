#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>

struct Node_bfs
{
	int color;
	struct Node_bfs *parent;
}*arr[10000];

//white = 0
//gray  = 1
//black = 2

struct Node_dfs
{
	int visited;
	struct Node_dfs *parent1;
}*arr1[10000];

struct List
{
	int key;
	struct List *next;	
}*adj[10000];


int i, n, k, j=0, r, top=-1, p, front=-1, rear=-1, time = 0, flag1 = 0;
int q[10000];

struct List *list = NULL;

void enqueue(int val);
int dequeue();
void push(int ele);
int pop();
void bfs(struct List *adj[], int st, int end);
void dfs(struct List *adj[], int st, int end);

void main()
{
	char ch;
	char str[3];
	int total=0, flag=0, st, end;
	scanf("%d",&total);
	n = total;

	for(i=0; i<n; i++)
	{
		adj[i] = (struct List *)malloc(sizeof(struct List));
		adj[i]->key = i;
		adj[i]->next = NULL;	
	}
	for(i=0; i<n; i++)
	{
		arr[i] = (struct Node_bfs *)malloc(sizeof(struct Node_bfs));
		arr[i]->parent = NULL;
		arr1[i] = (struct Node_dfs *)malloc(sizeof(struct Node_dfs));
		arr1[i]->parent1 = NULL;	
	}
	j=0;
	scanf("%c",&ch);
	scanf("%c",&ch);
	while(j<n)
	{	
		if(j!=0)
			scanf("%c",&ch);
		while(ch!='\n')
		{
			while(isdigit(ch))
			{
				total = 0;
				while(ch != ' ' && ch !='\n')
				{
					total = total*10 + (int)ch - 48;
					scanf("%c",&ch);
				}
				if(ch == '\n')
				{
					list = adj[j];
					while(list->next != NULL)
						list = list->next;
					struct List *temp = (struct List *)malloc(sizeof(struct List));
					temp->key = total;
					temp->next = NULL;
					list->next = temp;
					flag = 1;	
					break;
				}	
				else
				{
					list = adj[j];
					while(list->next != NULL)
						list = list->next;
					struct List *temp = (struct List *)malloc(sizeof(struct List));
					temp->key = total;
					temp->next = NULL;
					list->next = temp;
					scanf("%c",&ch);
				}	
			}
		}
		if(flag == 1)
		{
			flag = 0;
		}	
		j++;
	}

	while(1)
	{
		scanf("%s", str);
		if(strcmp(str, "bfs")==0)
		{
			scanf("%d %d", &st, &end);
			bfs(adj, st, end);
			printf("\n");
		}
		else if(strcmp(str, "dfs")==0)
		{
			scanf("%d %d", &st, &end);
			dfs(adj, st, end);
			printf("\n");
		}
		else if(strcmp(str, "stp")==0)
			exit(1);
	}
	return;
}

void bfs(struct List *adj[], int st, int end)
{
	for(i=0; i<n; i++)
	{
		if(i == st)
			continue;
		arr[i]->color = 0;
		arr[i]->parent = NULL;	
	}
	arr[st]->color = 1;
	arr[st]->parent = NULL;
	rear=-1;
	front=-1;
	enqueue(st);
	while(front != rear)
	{
		r = dequeue();
		list = adj[r]->next;
		while(list)
		{
			p = list->key;
			if(arr[p]->color == 0)
			{
				arr[p]->color = 1;
				arr[p]->parent = arr[r];
				enqueue(p);
			}
			list = list->next;
		}
		arr[r]->color = 2;
		printf("%d ", r);
		if(r == end)
			break;
	}
	return;
}

void dfs(struct List *adj[], int st, int end)
{
	for(i=0; i<n; i++)
	{
		if(i == st)
			continue;
		arr1[i]->visited = 0;
		arr1[i]->parent1 = NULL;	
	}
	arr1[st]->visited = 1;
	arr1[st]->parent1 = NULL;
	top=-1;
	push(st);
	while(top!=-1)
	{
		r = pop();
		list = adj[r]->next;
		while(list)
		{
			p = list->key;
			if(arr1[p]->visited == 0)
			{
				arr1[p]->visited = 1;
				arr1[p]->parent1 = arr1[r];
				push(p);
			}
			list = list->next;
		}
		arr1[r]->visited = 2;
		printf("%d ", r);
		if(r == end)
			break;
	}
	return;
}

int pop()
{
	if(top==-1)
	{
		printf("ERROR\n");
		return 0;
	}
	else
	{	
		top--;
		return q[top+1];
	}		
}

void push(int ele)
{
	top++;
	q[top] = ele;
	return;
}

void enqueue(int val)
{
	rear++;
	q[rear] = val;
	return;
}

int dequeue()
{
	if(front==rear)
	{
		rear=-1;
		front=-1;
		printf("ERROR\n");
		return 0;
	}	
	else
	{	
		front++;
		return q[front];
	}	
}