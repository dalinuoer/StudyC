#include<stdio.h>
#define N 3    //学生数
#define M 3    //课程数
struct Date
{
    int year;
    int month;
    int day;
};
struct Student
{
    char num[20];
    char name[20];
    char sex;
    struct Date birthday;
    float score[M];
    float aver;
}stu[N];
void input()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		printf("Please input the imformation of student %d:\n",i+1);
		printf("number:");
		scanf("%s",stu[i].num);
		getchar();
		printf("name:");
		scanf("%s",stu[i].name);
		getchar();
		printf("sex(M/F):");
		scanf("%c",&stu[i].sex);
		printf("birthday(**** ** **):");
		scanf("%d%d%d",&stu[i].birthday.year,&stu[i].birthday.month,&stu[i].birthday.day);
		for(j=0;j<M;j++)
		{
			printf("score%d:",j+1);
			scanf("%f",&stu[i].score[j]);
		}
	}
}
void average()
{
	int i,j;
	float sum;
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=0;j<M;j++)
			sum+=stu[i].score[j];
		stu[i].aver=sum/M;
	}
}
void print(struct Student stu[])
{
	int i,j;
	printf("序号         学号         性别  出生日期 score1 score2 score3 average\n");
	for(i=0;i<N;i++)
    {
        printf("%-10d",i+1);
        printf("%-13s%5c",stu[i].num,stu[i].sex);
        printf("    %d%02d%02d",stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day);
        for(j=0;j<M;j++)
        {
            printf("%7.1f",stu[i].score[j]);
        }
        printf("%7.1f",stu[i].aver);
        printf("\n");
    }
}
void sort(struct Student stu[])
{
	int i,j,k;
	struct Student t;
	for(i=0;i<N-1;i++)
    {
        k=i;
        for(j=i+1;j<N;j++)
            if(stu[k].aver<stu[j].aver) k=j;
        if(k!=i)
        {
            t=stu[k];
            stu[k]=stu[i];
            stu[i]=t;
        }
    }
}
int main()
{
	input();
	average();
	sort(stu);
    print(stu);
	return 0;
}

