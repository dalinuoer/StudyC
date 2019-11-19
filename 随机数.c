#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i;
    srand((unsigned)time(NULL));
    for(i=1;i<=10;i++)
        printf("%d ",rand()%100+1);		//100ÒÔÄÚ
    return 0;
}
