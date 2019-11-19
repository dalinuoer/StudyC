#include <stdio.h>
#include <stdlib.h>
#define N 101
int main()
{
    int n,m;
    int f(int n,int m);
    printf("请输入人数和报数：");
    scanf("%d%d",&n,&m);
    printf("出圈顺序为:");
    printf("\n最后留下的是%d号",f(n,m));
    return 0;
}

int f(int n,int m)
{
    int a[N]={0};
    int i,t=n,p=0,flag;
    for(i=1;i<=n;i++)
        *(a+i)=1;
    i=1;
    while(t!=1)
    {
        if(*(a+i)!=0)
        {
            p++;
            p=p%m;
            if(p==0)
            {
                *(a+i)=0;
                t--;
                printf("%d ",i);
            }
        }
        i++;
        if(i==n+1)
            i=1;
    }
    for(i=1;i<=n;i++)
        if(*(a+i)!=0)
            flag=i;
    return flag;
}
