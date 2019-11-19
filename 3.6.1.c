#include<stdio.h>
int main()
{
    char c;
    printf("原文为：");
    scanf("%c",&c);
    printf("密文为：");
    while(c!='\n')
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			if(c>='W'&&c<='Z'||c>='w'&&c<='z')c=c-22;
			else c=c+4;
		}
		printf("%c",c);
		scanf("%c",&c);
	}
	printf("\n");
	return 0;
}
