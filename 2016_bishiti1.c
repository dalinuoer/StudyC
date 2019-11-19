//亲和数：如果两个自然数a和b，a的所有除本身以外的因数之和等于b，
//b的所有除本身以外的因数之和等于a，则称a，b是一对亲和数。（例如：
//220和284:，因为220=1+2+4+71+142，284=1+2+4+5+10+11+20+22+44+55+110，
//所以220和284是一对亲和数）请编写一个程序，输出20000以内所有的亲和数对并统计该指定范围内有多少对亲和数。
#include<stdio.h>
#define N 20000
int yinshuhe(int n)			//求一个数除了它本身的因数和
{
	int sum,i;
	sum=0;
	for(i=2;i*i<n;i++)
		if(n%i==0) sum=sum+i+n/i;
	return(sum+1);
}

void qinheshu()
{
	int a,b,count=0;
	printf("%d以内的亲和数有：\n",N);
	for(a=2;a<=N;a++)
	{
		b=yinshuhe(a);
		if(yinshuhe(b)==a)
		{
			printf("%d--%d\t",a,b);
			count++;
			if(count%5==0) printf("\n");
		}
	}
	if(count%5!=0) printf("\n");
	printf("一共有%d对\n",count);
}

int main()
{
	qinheshu();
	return 0;
}