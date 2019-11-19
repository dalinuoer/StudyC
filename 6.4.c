#include<stdio.h>
int main()
{
    int i,n,mid,bot=0,top=8;
    int a[10]={1,2,3,4,5,6,7,9,11};
    printf("原数组为：");
    for(i=0;i<=8;i++) printf("%3d",a[i]);
    printf("\n请输入一个数：");
    scanf("%d",&n);
    if(n>a[8]) a[9]=n;
    else if(n<a[0])
    {
        for(i=8;i>=0;i--)
            a[i+1]=a[i];
        a[0]=n;
    }
    else
    {
        do
        {
            mid=(bot+top)/2;
            if(a[mid]<n) bot=mid;
            else top=mid;
        }
        while(bot+1!=top);
        for(i=8;i>=top;i--)
            a[i+1]=a[i];
        a[top]=n;
    }
    printf("新数列为：");
    for(i=0;i<10;i++)
        printf("%3d",a[i]);
    return 0;
}
