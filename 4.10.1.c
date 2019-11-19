#include<stdio.h>
int main()
{
    int c;
    float I;
    printf("请输入当月利润（元）：");
    scanf("%f",&I);
    printf("应发奖金为（元）：");
    c=I/100000;
    switch(c)
    {
		case 0:printf("%.2f",I*0.1);break;
		case 1:printf("%.2f",(I-100000)*0.075+100000*0.1);break;
		case 2:
		case 3:printf("%.2f",100000*0.1+100000*0.075+(I-200000)*0.05);break;
		case 4:
		case 5:printf("%.2f",100000*0.1+100000*0.07+200000*0.05+(I-400000)*0.03);break;
		case 6:
		case 7:
		case 8:
		case 9:printf("%.2f",100000*0.1+100000*0.075+200000*0.05+200000*0.03+(I-600000)*0.015);break;
		default:printf("%.2f",100000*0.1+100000*0.075+200000*0.05+200000*0.03+400000*0.015+(I-1000000)*0.01);

    }
    printf("\n");
	return 0;
}

