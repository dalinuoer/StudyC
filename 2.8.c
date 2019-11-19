#include<stdio.h>
int main()
{
    int start=2000,end=2200;
    int x=0;
    printf("%d-%d年之间的闰年有：\n",start,end);
    while (start<=end)
    {
       if((start%4==0)&&(start%100!=0))
			{
				printf("%d  ",start);
				x++;
				if (x%10==0)
					printf("\n");
			}
       if((start%100==0)&&(start%400==0))
			{
				printf("%d  ",start);
				 x++;
				if (x%10==0)
					printf("\n");
			}
       start++;
	   
    }
	if(x%10!=0)
		printf("\n一共有%d个！\n",x);
	else 
		printf("一共有%d个！\n",x);
    return 0;

}
