#include<stdio.h>
#define N 10
int main()
{
    printf("请输入%d个数：",N);
    int m=0,n=0;
    int a[N+1];
    for(m=0;m<10;m++)
        scanf("%d",&a[m]);
    void sort(int a[]);
    sort(a);
    printf("逆序为：");
    for(n=0;n<10;n++)
        printf("%d ",a[n]);
    printf("\n");
    return 0;
}

//冒泡法排逆序
void sort(int a[])
{
    int i,j,k,t,n=N;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }

    }
}
