#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Max_s=0,Max_c=0;
int main()
{
    void aver_s(float array[][5]);
    void aver_c(float array[][5]);
    float max(float array[][5]);
    float fangcha(float array[][5]);
    void initial(float arry[][5]);
    float score[3][5]={{70,70,70,70,70},{70,70,70,70,70},{70,70,70,70,70}};
    //float score[3][5]={{70,70,70,70,70},{70,70,70,100,70},{70,70,70,70,70}};
    /*
    float score[3][5];
    initial(score);
    */
    printf("学生的平均分为：");
    aver_s(score);
    printf("\n");
    printf("每门课的平均分为：");
    aver_c(score);
    printf("\n");
    printf("所有分数中最高分为：");
    float MAX;
    MAX=max(score);
    printf("%6.2f",MAX);
    printf("是第%d个学生的第%d门课",Max_s,Max_c);
    printf("\n");
    printf("平均分的方差为：");
    float PJF;
    PJF=fangcha(score);
    printf("%6.2f",PJF);
    printf("\n");
    return 0;
}

//求每个学生平均分的函数
void aver_s(float array[][5])
{
    int i,j;
    float sum,aver_s;
    for(i=0;i<3;i++)
    {
        sum=0;
        for(j=0;j<5;j++)
            sum=sum+array[i][j];
        aver_s=sum/5;
        printf("%6.2f",aver_s);
    }
}

//求每门课平均分的函数
void aver_c(float array[][5])
{
    int i,j;
    float sum,aver_c;
    for(j=0;j<5;j++)
    {
        sum=0;
        for(i=0;i<3;i++)
            sum=sum+array[i][j];
        aver_c=sum/3;
        printf("%6.2f",aver_c);

    }

}

//求所有分数中最高分及所对应学生和课程的函数
float max(float array[][5])
{
    float Max;
    int i,j;
    Max=array[0][0];
    Max_s=1;
    Max_c=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
        {
            if(array[i][j]>Max)
            {
                Max=array[i][j];
                Max_s=i+1;
                Max_c=j+1;
            }
        }
    }
    return(Max);
}

//求平均分方差的函数
float fangcha(float array[][5])
{
    float a[3];
    int i,j,k,m;
    float sum,aver_s,sum1,sum11,sum2,sum22,pjf;
    for(i=0;i<3;i++)
    {
        sum=0;
        for(j=0;j<5;j++)
        {
            sum=sum+array[i][j];
        }
        aver_s=sum/5;
        a[i]=aver_s;
    }
    sum1=a[0]*a[0];
    for(k=1;k<3;k++)
        sum1=sum1+a[k]*a[k];
    sum11=sum1/3;
    sum2=a[0];
    for(m=1;m<3;m++)
        sum2=sum2+a[m];
    sum22=(sum2/3)*(sum2/3);
    pjf=sum11-sum22;
    return(pjf);
}
//生成随机数函数
void initial(float array[][5])
{
    int i,j;
    srand((unsigned)time(NULL));
    for(i=0;i<3;i++)
        for(j=0;j<5;j++)
        {
            array[i][j]=rand()%40+60;
        }

}










