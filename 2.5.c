#include<stdio.h>
int main()
{
   int a,max;
   printf("������ʮ��������");
   scanf("%d",&a);
   int i=1;
   max=a;
   while (i<10)
   {
       scanf("%d",&a);
       if(a>max)max=a;
       else max=max ;
       i++;
   }
   printf("\n�����ǣ�%d",max);
   return 0;


}
