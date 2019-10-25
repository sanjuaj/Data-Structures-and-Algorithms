#include<stdio.h>
int main()
{
	FILE *fptr1, *fptr2;
	int ch;
	char s = ' ';
	fptr1 = fopen("in.txt", "r");
	fptr2 = fopen("out.txt", "w");
	if(!fptr1)
	{
		printf("File doesn't exist.\n");
		return 0;	
	}
	ch = getc(fptr1);
	while(ch != EOF)
	{
		if(ch == ' ' || ch == '\t')
		{
			fputc(s, fptr2);
			while(ch == ' ' || ch == '\t')
			{
				ch = getc(fptr1);
			}
		}
		fputc(ch, fptr2);
		ch = getc(fptr1);	 
	}
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}

