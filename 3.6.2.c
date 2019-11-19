#include<stdio.h>
int main()
{
	char c;
	printf("ԭ��Ϊ��");
	c=getchar();
	printf("����Ϊ��");
	while(c!='\n')
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			if(c>='W'&&c<='Z'||c>='w'&&c<='z')
				c=c-22;
			else 
				c=c+4;
		}
		//printf("%c",c);
		putchar(c);

		c=getchar();
	}
	printf("\n");
	return 0;
}