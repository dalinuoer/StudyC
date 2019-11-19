#include<stdio.h>
int main()
{
    int n;
    printf("请输入n(1<=n<=10)：");
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=2*n-1;i++)    //行数
    {
        if((1<=i)&&(i<=n))    //1~n行
        {
            for(j=1;j<=(n-i);j++)
                printf(" ");
            for(k=1;k<=(2*i-1);k++)
                printf("*");
            printf("\n");
        }
        else if(((n+1)<=i)&&(i<=(2*n-1)))   //n+1~2n-1行
        {
            for(j=1;j<=(i-n);j++)
                printf(" ");
            for(k=1;k<=(4*n-2*i-1);k++)
                printf("*");
            printf("\n");
        }

    }
    return 0;
}
