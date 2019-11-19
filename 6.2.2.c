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

//选择法排逆序
void sort(int a[])
{
    int i,j,k,t;
    for(i=0;i<N-1;i++)
    {
        k=i;
        for(j=i+1;j<N;j++)
            if(a[k]<a[j]) k=j;
        if(k!=i)
        {
            t=a[k];
            a[k]=a[i];
            a[i]=t;
        }
    }
}
