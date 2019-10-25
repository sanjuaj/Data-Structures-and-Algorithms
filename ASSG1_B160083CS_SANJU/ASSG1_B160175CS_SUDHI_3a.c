#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char* str, int i, int n)
{
	if(i<n-i-1)
	{
		*(str+i)= *(str+i) + *(str+n-i-1);
		*(str+n-i-1) = *(str+i) - *(str+n-i-1);
		*(str+i) = *(str+i) - *(str+n-i-1);
		reverse(str, i+1, n);
	}
}
int main()
{
	int l;
	char *str;
	str = (char*)malloc(1000000000*sizeof(char));
	scanf("%[^\n]s", str);
	l = strlen(str);
	str = (char*)realloc(str, l*sizeof(char));
	reverse(str, 0, l);
	printf("%s", str);
	free(str);
	return 0;
}

