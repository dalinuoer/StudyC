#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	#define N 20
	char str[N];
	printf("原文为：");
	gets(str);
	printf("密文为：");
	int i,k;
	char c;
	i=strlen(str);
	for(k=0;k<i;k++)
		{
		    if(str[k]!='\n')
                if((str[k]>='a'&&str[k]<='z')||(str[k]>='A'&&str[k]<='Z'))
                {
                    if(str[k]>='W'&&str[k]<='Z'||str[k]>='w'&&str[k]<='z')str[k]=str[k]-22;
                    else str[k]=str[k]+4;
                }
		}
    puts(str);
	return 0;
}



