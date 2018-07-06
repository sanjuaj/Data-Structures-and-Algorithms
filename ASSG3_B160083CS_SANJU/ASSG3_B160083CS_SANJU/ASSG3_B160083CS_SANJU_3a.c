#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
long int array[100];
int rear=0;
int front=0;
//int p=-1;

void print_queue()
{
	int i;
    if (front==rear)
		printf("-1\n");
    else if (front<rear)
    {
       	for (i = front; i < rear; i++)
       		printf("%ld ",array[i]);
        printf("\n");
    }
    else
    {
    	for (i=front; i<n; i++)
    		printf("%ld ",array[i]);
    	for (i = 0; i < rear; i++)
       		printf("%ld ",array[i]);
       	printf("\n");
    }

}

void enqueue(long int m)
{
	if ((rear-front)==-1 || (rear-front)==n-1)
        printf("-2 \n");
    else
    {
        array[rear]=m;
        if (rear==n-1)
            rear = 0;
        else
            rear++;
        //print_queue();
    }
}

void dequeue()
{
    if (front==rear)
    {
    	printf("-1 \n");
    }
    else if (front==n-1)
    {
    	printf("%ld \n",array[front]);
    	front=0;
    }
    else
    {
    	printf("%ld \n",array[front]);
    	front++;
    }
}

void main()
{	
    char c;
	long int m;
	scanf("%d",&n);
	fflush(stdin);
	n++;
	while(1)
	{
	    scanf("%c",&c);
	    if(c=='e')
	    {
		    scanf("%ld",&m);
		    enqueue(m);
	    }
	    if(c=='d')
		    dequeue();
	    if(c=='p')
		    print_queue();
	    if(c=='s')
		    break;
    }
}

