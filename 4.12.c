#include<stdio.h>
#include<math.h>
int main()
{
    float x,y,m,n;
    printf("请输入一点的坐标（x,y）:");
    scanf("%f,%f",&x,&y);
    printf("该点建筑物的高度为：");
    m=fabs(x)-2;
    n=fabs(y)-2;
    if((m*m+n*n)<=1)printf("10M\n");
    else printf("0\n");
    return 0;
}
