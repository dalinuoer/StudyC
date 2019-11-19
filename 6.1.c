#include<stdio.h>
#include<math.h>
#define N 1000000
int main()
{

    int m,n,x,y;
    int a[N+1];
    for(y=1;y<=N;y++)
        a[y]=y;
    a[1]=0;
    for(n=2;n<sqrt(N);n++)
    {
        for(m=n+1;m<=N;m++)
        {
            if((a[m]!=0)&&(a[n]!=0))
                if(a[m]%a[n]==0) a[m]=0;
        }
    }
    for(m=1,x=0;m<=N;m++)
    {
        if(a[m]!=0) x++;
    }
    printf("%d",N);
    printf("以内的素数有%d个\n",x);
    return 0;
}
