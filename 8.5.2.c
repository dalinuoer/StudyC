#include<stdio.h>
int main()
{
    void f(int n);
    int n;
    printf("\n请输入人数n:");
    scanf("%d",&n);
    f(n);
    return 0;
}

void f(int n)
{
    int i,k,m,a[50],*p;
    p=a;
    for(i=0;i<n;i++)
        *(p+i)=i+1;
    i=0;
    k=0;
    m=0;
    while(m<n-1)
    {
        if(*(p+i)!=0) k++;
        if(k==3)
        {
            *(p+i)=0;
            k=0;
            m++;
        }
        i++;
        if(i==n) i=0;
    }
    while(*p==0) p++;
    printf("最后活下来的是第%d个\n",*p);
}
