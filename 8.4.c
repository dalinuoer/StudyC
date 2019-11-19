#include<stdio.h>
int main()
{
   void move(int arr[],int m);
   int m,i;
   int a[10]={1,2,3,4,5,6,7,8,9,10};
   printf("请输入m:");
   scanf("%d",&m);
   move(a,m);
   printf("结果为：");
   for(i=0;i<10;i++)
        printf("%d   ",a[i]);
   printf("\n");
   return 0;
}

void move(int arr[],int m)
{
    int *p,arr_end;
    arr_end=*(arr+9);
    for(p=arr+9;p>arr;p--)
    {
        *p=*(p-1);
    }
    *arr=arr_end;
    m--;
    if(m>0)
        move(arr,m);
}
