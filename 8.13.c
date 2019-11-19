#include<stdio.h>
#include<math.h>
int main()
{
    void ff();
    ff();
    return 0;
}

void ff()
{
    double f(double(*p)(double),double a,double b,int n);
    double f1(double x);
    double f2(double x);
    double f3(double x);
    void caidan();
    caidan();
    int x;
    printf("请输入序号：");
    scanf("%d",&x);
    double a,b,d;
    double (*p)(double);
    int n=10000000;
    if(x==1)
    {
        printf("请输入积分下限和上限：");
        scanf("%lf,%lf",&a,&b);
        p=f1;
        d=f(p,a,b,n);
        printf("sin(x)在%lf到%lf上的定积分是：%lf\n",a,b,d);
        ff();
    }
    else if(x==2)
    {
        printf("请输入积分下限和上限：");
        scanf("%lf,%lf",&a,&b);
        p=f2;
        d=f(p,a,b,n);
        printf("cos(x)在%lf到%lf上的定积分是：%lf\n",a,b,d);
        ff();
    }
    else if(x==3)
    {
        printf("请输入积分下限和上限：");
        scanf("%lf,%lf",&a,&b);
        p=f3;
        d=f(p,a,b,n);
        printf("exp(x)在%lf到%lf上的定积分是：%lf\n",a,b,d);
        ff();
    }
    else if(x==0)
    {
        printf("程序结束。\n");
        printf("***************************\n");
    }
    else
    {
        printf("您输入的序号有误,请检查后重新输入。\n");
        ff();
    }

}

void caidan()
{
    printf("0.exit\n");
    printf("1.sin(x)\n");
    printf("2.cos(x)\n");
    printf("3.exp(x)\n");
}

//矩形法求积分
double f(double(*p)(double),double a,double b,int n)
{
    double h,s,c;
    int i;
    h=(b-a)/n;
    s=0;
    c=a;
    for(i=1;i<=n;i++)
    {
        c=c+h;
        s=s+(*p)(c)*h;
    }
    return (s);
}
/*
//梯形法求积分
double f(double(*p)(double),double a,double b,int n)
{
    double h,s,c1,c2;
    int i;
    h=(b-a)/n;
    s=0;
    c1=a;
    for(i=1;i<=n;i++)
    {
        c1=c1+h;
        c2=c1+h;
        s=s+(((*p)(c1)+(*p)(c2))*h/2);
    }
    return (s);
}
*/
double f1(double x)
{
    return sin(x);
}

double f2(double x)
{
    return cos(x);
}

double f3(double x)
{
    return exp(x);
}
