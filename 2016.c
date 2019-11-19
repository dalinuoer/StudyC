#include<stdio.h>						//2016年上机题——包裹费用问题
#include<math.h>
//计算运费
void yunfei()
{
	int a;
	float w,price=0;
	printf("Please input the area and weight:");
	scanf("%d,%f",&a,&w);
	if(a<0||a>4) printf("Erroe in Area\n");
	else if(w<0) printf("Error in Weight\n");
	else if((a<0||a>4)&&(w<0)) printf("Errors in Area and Weight\n");
	else
	{
		w=ceil(w);
		switch(a)
		{
		case 0:
				price=10+(w-1)*3;
				break;
		case 1:
				price=10+(w-1)*4;
				break;
		case 2:
				price=15+(w-1)*5;
				break;
		case 3:
				price=15+(w-1)*6.5;
				break;
		case 4:
				price=15+(w-1)*10;
				break;
		}
	}
	printf("Price:%.2f\n",price);
}

int main()
{
	yunfei();
	return 0;
}
