#include<stdio.h>
int main()
{
    int year,month,day,d;
    int jst(int a,int b,int c);
    printf("请输入年月日：");
    scanf("%d%d%d",&year,&month,&day);
    d=jst(year,month,day);
    printf("%d年是%d月%d日是%d年第%d天",year,month,day,year,d);
    return 0;
}

//计算某日是该年第几天
int jst(int a,int b,int c)
{
    int sum,sum2,i;
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((a%4==0)&&(a%100!=0))
        months[1]=29;
    if(a%400==0)
        months[1]=29;
    sum=0;
    for(i=0;i<b-1;i++)
        sum=sum+months[i];
    sum2=sum+c;
    return(sum2);
}
