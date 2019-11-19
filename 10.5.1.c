#include<stdio.h>
#include<stdlib.h>
#define N 3    //学生数
#define M 3    //课程数
struct date
{
    int year;
    int month;
    int day;
};
struct student
{
    char num[20];
    char name[20];
    char sex;
    struct date birthday;
    float score[M];
    float aver;
}stu[N];

void date_into_file()
{
    FILE *fp;
    int i;
    if((fp=fopen("stu.dat","wb"))==NULL)
    {
        printf("The file can not open\n");
        return;
    }
    for(i=0;i<N;i++)
    {
        if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
        {
            printf("File write error\n");
            return;
        }
    }
    fclose(fp);
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

void date_input()
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
	average();
	date_into_file();
}

int main()
{
    date_input();
    return 0;
}
