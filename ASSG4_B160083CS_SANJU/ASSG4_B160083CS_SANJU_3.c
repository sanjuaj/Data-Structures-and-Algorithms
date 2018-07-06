#include<stdio.h>
#include<stdlib.h>

struct disjoint_set
{
	int data[10000];
	int rank[10000];
	int count;
};

struct disjoint_set new_set(struct disjoint_set t)
{
	int i;
	for(i=0;i<10001;i++)
	{
		t.data[i]=-5;
		t.rank[i]=0;
	}
	t.count=0;
	return t;
}

int makeset(struct disjoint_set *t1,struct disjoint_set *t2,struct disjoint_set *t3,struct disjoint_set *t4, int x)
{
	if(t1->data[x]!=-5)
	{
		printf("PRESENT\n");
		return -5;
	}
	t1->data[x]=x;
	t1->rank[x]=1;
	t2->data[x]=x;
	t2->rank[x]=1;
	t3->data[x]=x;
	t3->rank[x]=1;
	t4->data[x]=x;
	t4->rank[x]=1;
	printf("%d\n",x);
}

int find(struct disjoint_set *t, int x)
{
	t->count++;
	if(t->data[x]==-5)
		return -5;
	else if(t->data[x]==x)
		return x;
	else
		return find(t,t->data[x]);
}

int find_paircomp(struct disjoint_set *t, int x)
{
	t->count++;
	if(t->data[x]==-5)
		return -5;
	else if(t->data[x]==x)
		return x;
	else
	{
		//int k=t->data[x];
		t->data[x]=find_paircomp(t,t->data[x]);
		/*if(t->data[x]!=k)
		{
			t->rank[t->data[x]]--;
		}*/
		return t->data[x];
	}
}

int union_no_mod(struct disjoint_set *t, int x, int y)
{
	int repx=find(t,x);
	int repy=find(t,y);
	if(repx==-5||repy==-5)
		return -5;
	if(repx==repy)
		return repx;
	t->data[repy]=repx;
	return repx;
}

int union_rank(struct disjoint_set *t, int x, int y)
{
	int repx=find(t,x);
	int repy=find(t,y);
	if(repx==-5||repy==-5)
		return -5;
	if(repx==repy)
		return repx;
	if(t->rank[repx]>t->rank[repy])
	{
		t->data[repy]=repx;
		return repx;
	}
	else if (t->rank[repx]<t->rank[repy])
	{
		t->data[repx]=repy;
		return repy;
	}
	t->data[repy]=repx;
	t->rank[repx]++;
	return repx;
}

int union_paircomp(struct disjoint_set *t, int x, int y)
{
	int repx=find_paircomp(t,x);
	int repy=find_paircomp(t,y);
	if(repx==-5||repy==-5)
		return -5;
	if(repx==repy)
		return repx;
	t->data[repy]=repx;
	return repx;
}

int union_both_mod(struct disjoint_set *t, int x, int y)
{
	int repx=find_paircomp(t,x);
	int repy=find_paircomp(t,y);
	if(repx==-5||repy==-5)
		return -5;
	if(repx==repy)
		return repx;
	if(t->rank[repx]>t->rank[repy])
	{
		t->data[repy]=repx;
		return repx;
	}
	else if (t->rank[repx]<t->rank[repy])
	{
		t->data[repx]=repy;
		return repy;
	}
	t->data[repy]=repx;
	t->rank[repx]++;
	return repx;
}

void main()
{
	struct disjoint_set t1,t2,t3,t4;
	t1=new_set(t1);
	t2=new_set(t2);
	t3=new_set(t3);
	t4=new_set(t4);
	char ch;
	int x,y,n1,n2,n3,n4;
	while(1)
	{
		scanf("%c",&ch);
		switch(ch)
		{
			case 'm':
				scanf("%d",&x);
				makeset(&t1,&t2,&t3,&t4,x);
				break;
			case 'u':
				scanf("%d %d",&x,&y);
				n1=union_no_mod(&t1,x,y);
				n2=union_rank(&t2,x,y);
				n3=union_paircomp(&t3,x,y);
				n4=union_both_mod(&t4,x,y);
				if(n1==-5)
					printf("ERROR\n");
				else
					printf("%d %d %d %d\n",n1,n2,n3,n4);
				break;
			case 'f':
				scanf("%d",&x);
				n1=find(&t1,x);
				n2=find(&t2,x);
				n3=find_paircomp(&t3,x);
				n4=find_paircomp(&t4,x);
				if (n1==-5)
					printf("NOT FOUND\n");
				else
					printf("%d %d %d %d\n",n1,n2,n3,n4);
				break;
			case 's':
				printf("%d %d %d %d\n",t1.count,t2.count,t3.count,t4.count);
				exit(1);
			default:
				break;
		}
	}
}