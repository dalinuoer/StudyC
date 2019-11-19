#include<stdio.h>
#include<math.h>
int main()
{
    double f(double x);
    double f1(double x);
    double x0=1.5,x1;
    while(fabs(x0-x1)>=1e-6)
    {
        x1=x0;
        x0=x1-f(x1)/f1(x1);
    }
    printf("方程的根是：%lf",x1);
    return 0;

}

//方程函数
double f(double x)
{
    return(2*x*x*x-4*x*x+3*x-6);
}

//方程导数
double f1(double x)
{
    return(6*x*x-8*x+3);
}
