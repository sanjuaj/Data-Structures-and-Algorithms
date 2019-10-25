#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,c,len,a,k;
	scanf("%d", &c);
	scanf("%d", &len);
	char *str;
	str = (char*)malloc(len*sizeof(char));
	scanf(" %[^\n]s",str);
	scanf("%d",&k);
	if(k<0)
	{
		printf("Invalid number. Enter a positive constant\n");
	}
	else
	{
		k = k%26;
		if(c==1)
		{
			for(i=0;i<len;i++)
			{
				a = *(str+i);
				if(a>=65 && a<=90)
				{
					a = a+k;
					if(a>90)
					a=a-26;
				}
				else if(a>=97 && a<=122)
				{
					a = a+k;
					if(a>122)
					a=a-26;
				}
				printf("%c",a);
			}
		}
		else if(c==2)
		{
		        for(i=0;i<len;i++)
		        {
		                a = *(str+i);
		                if(a>=65 && a<=90)
		                {
		                        a = a-k;
		                        if(a<65)
		                        a=a+26;
		                }
		                else if(a>=97 && a<=122)
		                {
		                        a = a-k;
		                        if(a<97)
		                        a=a+26;
		                }
		                printf("%c",a);
		        }
		}
		else
		printf("Invalid choice. Choice should be either 1 or 2.\n");
	}
	free(str);
	return 0;
}
