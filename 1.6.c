#include<stdio.h>
int main()
{
	int max(int x,int y,int z);
	int a,b,c,d;
	printf("请输入三个整数（a,b,c）:");
	scanf("%d,%d,%d",&a,&b,&c);
	d=max(a,b,c);
	printf("max=%d\n",d);
	return 0;
}

//定义求三个整数中最大值的 max函数 
int max(int a,int b,int m)
{
	int n;
	if(a>b)n=a;
	else n=b;
	if(m>n)n=m;
	else n=n;
	return(n);
}
