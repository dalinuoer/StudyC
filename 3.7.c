#include<stdio.h>
int main()
{
	# define P 3.1415926
	double r,h;
	printf("请输入圆的半径r和输入圆柱的高h：");
	scanf("%lf %lf",&r,&h);
	printf("圆的周长为%.2f\n",2.0*P*r);
	printf("圆的面积为%.2f\n",P*r*r);
	printf("圆球的表面积为%.2f\n",4.0*P*r*r);
	printf("圆球的体积为%.2f\n",(4.0/3)*P*r*r*r);
	printf("圆柱的体积为%.2f\n",P*r*r*h);
	return 0;
}