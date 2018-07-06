#include<stdio.h>
#include<stdlib.h>

struct Node
{
    long int data;
    struct Node *next;
};

void printList(struct Node *h)
{
  while (h!=NULL)
  {
     printf("%ld ",h->data);
     h = h->next;
  }
}

void create_linked_list(struct Node *h)
{
    char input;
    long int num,d;
    long int sum=0;
    scanf("%c",&input);
    //fflush(stdin);
        //printf("%c", input);
    while(input!='\n')
    {
        if (input==' ')
        {
            d=sum;
            sum=0;
            struct Node *next1;
            next1=(struct Node *)malloc(sizeof(struct Node));
            next1->next=NULL;
            h->data=d;
            h->next=next1;
            h=h->next;
        }
        else
        {
            num=input-48;
            sum=sum*10+num;
        }
        input=getchar();
    }
    d=sum;
    h->data=d;
    h->next=NULL;
}
/*void create_linked_list(struct Node *h,long int d)
{
                struct Node *next1;
                next1=(struct Node *)malloc(sizeof(struct Node));
                next1->next=NULL;
                h->data=d;
                h->next=next1;
                //create_linked_list(next1);
}*/

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

int main()
{
    //long int n;
    //scanf("%ld ", &n);
    struct Node *h;
    h=(struct Node *)malloc(sizeof(struct Node));
    create_linked_list(h);
    reverse(&h);
    printList(h);
}
    