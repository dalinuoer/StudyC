#include<stdio.h>
#include<math.h>
int main()
{
    double x1,x2,x0;
    printf("请输入要求的数：");
    scanf("%lf,%lf",&x1,&x2);
    double f(double x);
    while(fabs(x2-x1)>=1e-6)
        {
            x0=(x1+x2)/2;
            if(f(x0)>0) x2=x0;
            else if(f(x0)<0) x1=x0;
            else printf("方程的根为%lf",x0);
        }
    printf("方程的根为:%lf",x0);
    return 0;

}

//方程的函数
double f(double x)
{
    return(2*x*x*x-4*x*x+3*x-6);
}
