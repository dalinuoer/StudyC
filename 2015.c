#include<stdio.h>					//有趣的数2015年上机题
//10^m
int chengfang(int m)
{
    int i,sum=1; 
    for(i=0;i<m;i++)
    {
        sum=sum*10;
    }
    return(sum);
}
//求一个数的位数
int weishu(int n)
{
    int count=1;
    while(n>=10)
    {
        n=n/10;
        count++;
    }
    return(count);
}

void number()
{
    int i,a,b,c,d,count=0;
    printf("They are:");
    for(i=1;i<=10000;i++)
    {
        a=i*i;
        b=weishu(i);
        c=chengfang(b);
        d=a%c;
        if(d==i)
        {
            printf("%5d",i);
            count++;
        }
    }
    printf("\nTotal:%d\n",count);
}

int main()
{
    number();
    return 0;
}
