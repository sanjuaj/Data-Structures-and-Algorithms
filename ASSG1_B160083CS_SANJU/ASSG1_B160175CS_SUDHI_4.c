#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Ratio
{
	int x;
	int y;
};
int gcd(int x, int y)
{
	if(x==0 || y==0)
		return 0;
	int r;	
	if(x>=y)
	{
		r = x%y;
		if(r==0)
		return y;
		else
		gcd(y,r);
	}
	else
	{ 
		r = y%x;
		if(r==0)
		return x;
		else
		gcd(x,r);
	}			
}
void simplify(int a, int b)
{
	int f;
	if(b==0)
	{
		printf("Division by 0 meaningless.\n");
		return;
	}
	else if((a<0 && b>0) || (a>0 && b<0))
	{
		a = abs(a);
		b = abs(b);
		f = gcd(a, b);
		a = a/f;
		b = b/f;
		printf("-%d/%d", a, b);
		return;
	}
	else
	{
		a = abs(a);
		b = abs(b);
		f = gcd(a, b);
		a = a/f;
		b = b/f;
		printf("%d/%d", a, b);
		return;
	}
}
void arrange(int *a, int *b)
{
	if(*b < 0)
	{
		*a =(*a)*(-1);
		*b =(*b)*(-1);
	}
	return;				
}
int subnum(struct Ratio a, struct Ratio b)
{
	return (((a.x)*(b.y))-((a.y)*(b.x)));
}
int main()
{
	struct Ratio r1,r2,res,*arr,temp;
	int option,f,n,temp1,i,j,l;
	scanf("%d", &option);
	switch(option)
	{
		case 1 : 
			scanf("%d %d", &r1.x, &r1.y);
			simplify(r1.x, r1.y);
			break;		
		case 2 : 
			scanf("%d %d", &r1.x, &r1.y);
			scanf("%d %d", &r2.x, &r2.y);
			arrange(&r1.x, &r1.y);
			arrange(&r2.x, &r2.y); 
			res.x = (r1.x * r2.y) + (r2.x * r1.y);
			res.y = r1.y * r2.y;
			r1.x = abs(res.x);
			r1.y = abs(res.y);
			f = gcd(r1.x, r1.y);
			if(f==0)
			{
				printf("0");
				break;
			}
			else
			{
				r1.x/=f;
				r1.y/=f;
				if((res.x>0 && res.y<0) || (res.x<0 && res.y>0))
					printf("-%d/%d",r1.x, r1.y);
				else
					printf("%d/%d",r1.x, r1.y); 		
				break;
			}	
		case 3 : 
			scanf("%d %d", &r1.x, &r1.y);
			scanf("%d %d", &r2.x, &r2.y);
			arrange(&r1.x, &r1.y);
			arrange(&r2.x, &r2.y);
			res.x = r1.x * r2.x;	
			res.y = r1.y * r2.y;
			r1.x = abs(res.x);
			r1.y = abs(res.y);
			f = gcd(r1.x, r1.y);
			if(f==0)
			{
				printf("0");
				break;
			}
			else
			{
				r1.x/=f;
				r1.y/=f;
				if((res.x>0 && res.y<0) || (res.x<0 && res.y>0))
					printf("-%d/%d",r1.x, r1.y);
				else
					printf("%d/%d",r1.x, r1.y); 		
				break;
			}
		case 4 : 
			scanf("%d",&n);
			arr = (struct Ratio*)malloc(n*sizeof(struct Ratio));
			for(i=0;i<n;i++)
			{
				scanf("%d %d", &(arr+i)->x, &(arr+i)->y);
			}
			for(i=0;i<n;i++)
			{
				arrange(&(arr+i)->x, &(arr+i)->y);
			}
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(subnum(*(arr+i),*(arr+j))>0)
					{
						temp = *(arr+i);
						*(arr+i) = *(arr+j);
						*(arr+j) = temp;
					}
				}
			}
			for(i=0;i<n;i++)
			{
				printf("%d/%d ",(arr+i)->x,(arr+i)->y);
			}
			free(arr);
			break;
		case 5 : 
			scanf("%d %d", &r1.x, &r1.y);
			simplify(r1.x, r1.y);
			break;	
	}
	return 0;	
}
