#include<stdio.h>
int main()
{
    int i,j,k,r,max,symbol;
    //int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int a[3][4]={1,2,3,13,5,6,14,8,9,10,11,12};
    printf("原矩阵为：\n");    //输出原矩阵
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
    //求鞍点
    for(i=0;i<3;i++)
    {
        max=a[i][0];
        r=0;
        for(j=0;j<4;j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                r=j;
            }
        symbol=1;
        for(k=0;k<3;k++)
            if(max>a[k][r])
            {
                symbol=0;
                continue;
            }
        if(symbol)
        {
            printf("\n鞍点为：");
            printf("%d",max);
            printf("\n在第%d行，第%d列",i+1,r+1);
            break;
        }
    }
   if(!symbol) printf("鞍点不存在\n");
   return 0;
}
