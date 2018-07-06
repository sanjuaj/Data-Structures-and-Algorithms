#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int key;
	struct node *left, *right, *parent;
};

struct node* create_node(struct node *bst, int k)
{
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	newnode->key = k;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = bst;
	return newnode;
}

struct node* insert(struct node *bst, int k)
{
	if (bst==NULL)
	{
		bst=create_node(bst,k);
	}
	else if((bst->key)>k)
	{
		if(bst->left==NULL)
			bst->left=create_node(bst,k);
		else
			bst->left=insert((bst->left),k);
	}
	else
	{
		if(bst->right==NULL)
			bst->right=create_node(bst,k);
		else
			bst->right=insert((bst->right),k);
	}
	return bst;
}

void search(struct node *bst, int k)
{
	if (bst==NULL)
	{
		printf("NOT FOUND\n");
	}
	else if ((bst->key)==k)
		printf("FOUND\n");
	else if ((bst->key)>k)
	{
		search((bst->left), k);
	}
	else
	{
		search((bst->right), k);
	}
}

void findMin(struct node *bst)
{
	if (bst==NULL)
	{
		printf("NIL\n");
	}
	else
	{
		struct node *temp=bst;
		while((temp->left)!=NULL)
		{
			temp=temp->left;
		}
		printf("%d\n", temp->key);
	}
}

void findMax(struct node *bst)
{
	if (bst==NULL)
	{
		printf("NIL\n");
	}
	else
	{
		struct node *temp=bst;
		while((temp->right)!=NULL)
		{
			temp=temp->right;
		}
		printf("%d\n", temp->key);
	}
}

void predecessor(struct node *bst, int k)
{
	struct node *y=(struct node*)malloc(sizeof(struct node));
	if (bst==NULL)
	{
		printf("NOT FOUND\n");
	}
	else if ((bst->key)==k)
	{
		if (bst->left!=NULL)
		{
			findMax(bst->left);
			return;
		}
		y=bst->parent;
		while ((y!=NULL) && (bst==y->left))
		{
			bst=y;
			y=y->parent;
		}
		if (y==NULL)
		{
			printf("NIL\n");
			return;
		}
		else
		{
			printf("%d\n",y->key);
			return;
		}
	}
	else if ((bst->key)>k)
	{
		predecessor((bst->left), k);
	}
	else
	{
		predecessor((bst->right), k);
	}
}
void successor(struct node *bst, int k)
{
	struct node *y=(struct node*)malloc(sizeof(struct node));
	if (bst==NULL)
	{
		printf("NOT FOUND\n");
	}
	else if ((bst->key)==k)
	{
		if (bst->right!=NULL)
		{
			findMin(bst->right);
			return;
		}
		y=bst->parent;
		while ((y!=NULL) && (bst==y->right))
		{
			bst=y;
			y=y->parent;
		}
		if (y==NULL)
		{
			printf("NIL\n");
			return;
		}
		else
		{
			printf("%d\n",y->key);
			return;
		}
	}
	else if ((bst->key)>k)
	{
		successor((bst->left), k);
	}
	else
	{
		successor((bst->right), k);
	}
}

/*void delete(struct node *bst, int k)
{
	struct node *p=bst;
	struct node *q=NULL;
	struct node *rp=(struct node*)malloc(sizeof(struct node));
	struct node *f=(struct node*)malloc(sizeof(struct node));
	struct node *s=(struct node*)malloc(sizeof(struct node));
	while((p!=NULL) && (p->key)!=k)
	{
		q=p;
		if (k<p->key)
			p=p->left;
		else
			p=p->right;
	}
	if (p==NULL)
	{
		return;
	}
	if (p->left==NULL)
	{
		rp=p->right;
	}
	else if (p->right==NULL)
	{
		rp=p->left;
	}
	else
	{
		f=p;
		rp=p->right;
		s=rp->left;
		while(s!=NULL)
		{
			f=rp;
			rp=s;
			s=rp->left;
		}
		if (f!=p)
		{
			f->left=rp->right;
			rp->right=p->right;
		}
		rp->left=p->left;
	}
	if (q==NULL)
	{
		bst=rp;
	}
	else if(p==q->left)
	{
		q->left=rp;
	}
	else
		p->right=rp;
}*/
struct node* findMinval(struct node *bst)
{
	if (bst==NULL)
	{
		return;
	}
	else
	{
		struct node *temp=bst;
		while((temp->left)!=NULL)
		{
			temp=temp->left;
		}
		return temp;
	}
}

struct node* search_tree(struct node *bst, int k)
{
	if (bst==NULL)
	{
		return;
	}
	else if ((bst->key)==k)
		return bst;
	else if ((bst->key)>k)
	{
		search_tree((bst->left), k);
	}
	else
	{
		search_tree((bst->right), k);
	}
}

struct node* transplant(struct node *bst,struct node *u,struct node *v)
{
	if (u->parent==NULL)
		bst=v;
	else if (u==(u->parent)->left)
		(u->parent)->left=v;
	else
	{
		(u->parent)->right=v;
	}
	if(v!=NULL)
	{
		v->parent=u->parent;
	}
	return bst;
}

struct node* delete(struct node* bst, int key)
{
	struct node *z=(struct node*)malloc(sizeof(struct node));
	struct node *y=(struct node*)malloc(sizeof(struct node));
	z=search_tree(bst, key);
	if (z->left==NULL)
		bst=transplant(bst,z,z->right);
	else if (z->right==NULL)
	{
		bst=transplant(bst,z,z->left);
	}
	else
	{
		y=findMinval(z->right);
		if(y->parent!=z)
		{
			bst=transplant(bst,y,y->right);
			y->right=z->right;
			(y->right)->parent=y;
		}
		bst=transplant(bst,z,y);
		y->left=z->left;
		(y->left)->parent=y;
	}
	return bst;
}
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root 
struct node* delete(struct node* bst, int key)
{
    // base case
    if (bst == NULL)
    	return bst;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < bst->key)
        bst->left = delete(bst->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > bst->key)
        bst->right = delete(bst->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (bst->left == NULL)
        {
            struct node *temp = bst->right;
            free(bst);
            return temp;
        }
        else if (bst->right == NULL)
        {
            struct node *temp = bst->left;
            free(bst);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = findMinval(bst->right);
 
        // Copy the inorder successor's content to this node
        bst->key = temp->key;
 
        // Delete the inorder successor
        bst->right = delete(bst->right, temp->key);
    }
    return bst;
}*/

void inorder(struct node* bst)
{
	if (bst==NULL)
	{
		return;
	}
	inorder(bst->left);
	printf("%d ",bst->key);
	inorder(bst->right);
}

void preorder(struct node* bst)
{
	if (bst==NULL)
	{
		return;
	}
	printf("%d ",bst->key);
	preorder(bst->left);
	preorder(bst->right);
}

void postorder(struct node* bst)
{
	if (bst==NULL)
	{
		return;
	}
	postorder(bst->left);
	postorder(bst->right);
	printf("%d ",bst->key);
}

void main()
{
	char inst[4];
	int k;
	struct node *bst=NULL;
	while(1)
	{
		scanf("%s",inst);
		//fflush(stdin);
		if (strcmp(inst,"stop")==0)
			exit(1);
		else if (strcmp(inst,"insr")==0)
		{
			scanf("%d",&k);
			bst=insert(bst,k);
		}
		else if (strcmp(inst,"srch")==0)
		{
			scanf("%d",&k);
			search(bst,k);
		}
		else if (strcmp(inst,"minm")==0)
			findMin(bst);
		else if (strcmp(inst,"maxm")==0)
			findMax(bst);
		else if (strcmp(inst,"pred")==0)
		{
			scanf("%d",&k);
			predecessor(bst,k);
		}
		else if (strcmp(inst,"succ")==0)
		{
			scanf("%d",&k);
			successor(bst,k);
		}
		else if (strcmp(inst,"delt")==0)
		{
			scanf("%d",&k);
			bst=delete(bst,k);
		}
		else if (strcmp(inst,"inor")==0)
		{
			inorder(bst);
			printf("\n");
		}
		else if (strcmp(inst,"prer")==0)
		{
			preorder(bst);
			printf("\n");
		}
		else if (strcmp(inst,"post")==0)
		{
			postorder(bst);
			printf("\n");
		}
	}
}