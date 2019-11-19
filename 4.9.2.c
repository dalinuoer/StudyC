#include<stdio.h>
int main()
{
    int n,i=0,k=0;
    int a[10]={0};
    printf("请输入一个不大于八位的数字:");
    scanf("%d",&n);
    if(n==0)
    {
        printf("各位是：0");
        printf("\n它是一个1位数");
        printf("\n逆序为：0");
    }
    else
    {
        while(n!=0)
        {
            a[i]=n%10;
            n=n/10;
            i++;
        }
        printf("各位是:");
        for(k=i-1;k>=0;k--)
            printf("%-2d",a[k]);
        printf("\n倒序:");
        for(k=0;k<i;k++)
            printf("%d",a[k]);
        printf("\n这是一个%d位数",i);
    }
    return 0;
}
