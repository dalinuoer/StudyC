#include<stdio.h>
int main()
{
   float p(int n,float x);
   int n;
   float x,b;
   printf("请输入n(n>=0,n为正整数)，x:");
   scanf("%d,%f",&n,&x);
   b=p(n,x);
   printf("此多项式的值为：%f",b);
   return 0;
}

//递归法求n阶勒让德多项式的值
float p(int n,float x)
{
    float a;
    if(n==0) a=1;
    else if(n==1) a=x;
    else a=((2*n-1)*x-p(n-1,x)-(n-1)*p(n-2,x))/n;
    return a;
}
