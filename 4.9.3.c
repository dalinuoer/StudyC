#include<stdio.h>
#include<math.h>
int main()
{
    int f(int x);
    int n;
    printf("请输入一个不超过八位的正整数：");
    scanf("%d",&n);
    printf("这个数的各位是：");
    int a[10]={0};
    int c,i=7,m,x=0,z=0;
    while(i>=0)
        {
            c=f(i);
            m=n/c;
            if(m!=0)
            {
               printf("%-2d",m);
               a[x]=m;
               n=n%c;
               i--;
               x++;

            }
            else i--;
        }
    printf("\n它是一个%d位数",x);
    printf("\n逆序为：");
    for(z=x-1;z>=0;z--)
        printf("%d",a[z]);
    return 0;
}

int f(int x)
{
    int i,s=1;
    for(i=1;i<=x;i++)
        s=s*10;
    return s;
}
