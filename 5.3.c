#include<stdio.h>
int main()
{
    int gys(int u,int v);
    int m,n,p,q;
    printf("请输入两个正整数（m,n）：");
    scanf("%d,%d",&m,&n);
    p=gys(m,n);
    q=(m*n)/p;
    printf("它们的最大公约数是：%d\n",p);
    printf("它们的最小公倍数是：%d\n",q);
    return 0;
}
//求两个正整数最大公约数的函数
int gys(int u,int v)
{
    int r;
    while(v!=0)
    {
        r=u%v;
        u=v;
        v=r;
    }
    return(u);
}
