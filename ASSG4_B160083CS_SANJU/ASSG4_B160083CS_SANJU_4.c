#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

int k=0;

struct node* create_node(int key)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->key = key;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int find_index(int inor[], int st, int end, int key)
{
	int t;
	for(t=st; t<=end; t++)
	{
		if(inor[t] == key)
			return t;
	}
}

struct node* createTree(int prer[], int inor[], int st, int end)
{
	if(st > end)
		return NULL;
	struct node *bt = create_node(prer[k]);
	k++;
	if(st == end)
	{
		return bt;
	}
	else
	{
		bt->left = createTree(prer, inor, st, find_index(inor, st, end, bt->key)-1);
		bt->right = createTree(prer, inor, find_index(inor, st, end, bt->key)+1, end);
		return bt;
	}		
}

void print(struct node *bt)
{
	printf("(");
	if(bt!=NULL)
	{
		printf("%d", bt->key);
		print(bt->left);
		print(bt->right);
	}
	printf(")");
}

void main()
{
	struct node *bt = NULL;
	int i,n;
	scanf("%d", &n);
	int *prer, *inor;
	prer=(int *)malloc(n*sizeof(int));
	inor=(int *)malloc(n*sizeof(int));
	for(i=0; i<n; i++)
	{
		scanf("%d", &prer[i]);
	}
	for(i=0; i<n; i++)
	{
		scanf("%d", &inor[i]);
	}
	bt=createTree(prer, inor, 0, n-1);	
	print(bt);
	printf("\n");
	return;
}
