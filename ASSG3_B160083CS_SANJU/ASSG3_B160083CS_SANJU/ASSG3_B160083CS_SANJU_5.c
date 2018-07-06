#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int s[10000];
int count=-1;

void print_eqn(char a[100000],int n)
{
	int temp[n];
	int i,last,num,sum=0;
	char *ele;
	ele=a;
	for (i=0;i<n;i++)
		temp[i]=-1;
	i=0;
	while (*ele!='\n')
	{
		if((isdigit(*ele)) && (*ele!=' '))
		{
			num=*ele-48;
			sum=sum*10+num;
		}
		else if (*ele=='/')
		{
			i=last-3;
			while(temp[i]!=-1)
			{
				i-=2;
			}
			temp[i]=-2;
		}
		else if (*ele=='*')
		{
			i=last-3;
			while(temp[i]!=-1)
			{
				i-=2;
			}
			temp[i]=-3;
		}
		else if (*ele=='+')
		{
			i=last-3;
			while(temp[i]!=-1)
			{
				i-=2;
			}
			temp[i]=-4;
		}
		else if (*ele=='-')
		{
			i=last-3;
			while(temp[i]!=-1)
			{
				i-=2;
			}
			temp[i]=-5;
		}
		else if (*ele=='^')
		{
			i=last-3;
			while(temp[i]!=-1)
			{
				i-=2;
			}
			temp[i]=-6;
		}
		else if (*ele=='%')
		{
			i=last-3;
			while(temp[i]!=-1)
			{
				i-=2;
			}
			temp[i]=-7;
		}
		else if ((isdigit(*(ele-1))) && (*ele==' '))
		{
			i=last;
			temp[i]=sum;
			i+=2;
			last=i;
			sum=0;
		}
		ele++;
	}
	for (i=0;i<n;i++)
	{
		if (temp[i]==-2)
			printf("/");
		else if (temp[i]==-3)
			printf("*");
		else if (temp[i]==-4)
			printf("+");
		else if (temp[i]==-5)
			printf("-");
		else if (temp[i]==-6)
			printf("^");
		else if (temp[i]==-7)
			printf("mod");
		else
			printf("%d",temp[i]);
	}
	printf("\n");

}
int power(int n1, int n2)
{
	int i,p=n1;
	if (n2==0)
		return 1;
	for (i=1; i<n2;i++)
	{
		p=p*n1;
	}
	return p;
}

void push(int e)
{
	count++;
	s[count]=e;
}

int pop()
{
	count--;
	return s[count+1];
}

void main()
{
	char a[100000];
	int num=0;
	int sum=0;
	int n=0;
	int n1,n2,n3;
	scanf(" %[^\n]%*c",a);
	char *ele;
	ele=a;
	while (*ele!='\n')
	{
		if((isdigit(*ele)) && (*ele!=' '))
		{
			num=*ele-48;
			sum=sum*10+num;
		}
		else if (*ele=='/')
		{
			n1=pop();
			n2=pop();
			n3=n2/n1;
			push(n3);
			n++;
		}
		else if (*ele=='*')
		{
			n1=pop();
			n2=pop();
			n3=n2*n1;
			push(n3);
			n++;
		}
		else if (*ele=='+')
		{
			n1=pop();
			n2=pop();
			n3=n2+n1;
			push(n3);
			n++;
		}
		else if (*ele=='-')
		{
			n1=pop();
			n2=pop();
			n3=n2-n1;
			push(n3);
			n++;
		}
		else if (*ele=='^')
		{
			n1=pop();
			n2=pop();
			n3=power(n2,n1);
			push(n3);
			n++;
		}
		else if (*ele=='%')
		{
			n1=pop();
			n2=pop();
			n3=n2%n1;
			push(n3);
			n++;
		}
		else if ((isdigit(*(ele-1))) && (*ele==' '))
		{
			push(sum);
			sum=0;
			n++;
		}
		ele++;
	}
	print_eqn(a,n);
	printf("%d",s[0]);
	printf("\n");
}