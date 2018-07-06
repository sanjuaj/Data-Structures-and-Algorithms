#include<stdio.h>
#include<stdlib.h>

struct Node
{
    long int data;
    struct Node *next;
};

void printList(struct Node *h)
{
	int flag=0;
  	while (h!= NULL)
  	{
  		if ((h->data)!=0)
  		{
  			flag=1;
  		}
  		if (flag==1)
  		{
    		printf("%ld", h->data);
    		h = h->next;
    	}
    	else
    	{
    		h=h->next;
    	}
    }
    if (flag==0)
    {
    	printf("0");
    }
}


void difference_of_digits(struct Node *h1, struct Node *h2)
{
    int diff, a, b;
    struct Node *temp;
    if (h1!=NULL)
    {
        if (h2!=NULL)
        {
            a=h1->data;
            b=h2->data;
            diff=a-b;
            if(diff<0)
            {
                temp=h1->next;
                temp->data=(temp->data)-1;
                diff+=10;
            }
            h1->data=diff;
            h1=h1->next;
            h2=h2->next;
            difference_of_digits(h1, h2);
        }
        else
        {
            a=h1->data;
            b=0;
            diff=a-b;
            if(diff<0)
            {
                temp=h1->next;
                temp->data=(temp->data)-1;
                diff+=10;
            }
            h1->data=diff;
            h1=h1->next;
            difference_of_digits(h1, h2);
        }
    }
}

long int create_linked_list(struct Node *h, long int n,long int size)
{
    if (n/10==0)
    {
        long int d;
        d=n%10;
        h->data=d;
        h->next=NULL;
        return size+1;
    }
    else
    {
        long int d;
        struct Node *next1;
        next1=(struct Node *)malloc(sizeof(struct Node));
        d=n%10;
        h->data=d;
        h->next=next1;
        return create_linked_list(next1, n/10, size+1);
    }
}

void reverse(struct Node **h)
{
    struct Node *prev = NULL;
    struct Node *current = *h;
    struct Node *next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *h=prev;
}

void subtract1(struct Node *h1, struct Node *h2, long int n1,long int n2 )
{   
    if (n1>n2)
    {
        difference_of_digits(h1,h2);
        reverse(&h1);
        printList(h1);
    }
    else
    {
        difference_of_digits(h2,h1);
        reverse(&h2);
        printList(h2);
    }
}


int main()
{
    long int n1,n2,s1,s2;
    scanf("%ld ", &n1);
    fflush(stdin);
    scanf("%ld", &n2);
    struct Node *h1, *h2;
    h1=(struct Node *)malloc(sizeof(struct Node));
    h2=(struct Node *)malloc(sizeof(struct Node));
    s1=create_linked_list(h1,n1,0);
    s2=create_linked_list(h2,n2,0);
    subtract1(h1,h2,n1,n2);
}
