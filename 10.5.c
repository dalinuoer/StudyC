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

void sort()
{
	FILE *fp1,*fp2;
	int i,j;
	struct student t;
	if((fp1=fopen("stu.dat","rb"))==NULL)
    {
        printf("The file can not open\n");
        exit(0);
    }
    if((fp2=fopen("stu_sort.dat","wb"))==NULL)
    {
        printf("The file write error\n");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        if(fread(&stu[i],sizeof(struct student),1,fp1)!=1)
        {
            printf("File read error\n");
            exit(0);
        }
    }
    for(i=1;i<N;i++)
    {
        for(j=0;j<N-i;j++)
        {
            if(stu[j].aver<stu[j+1].aver)
            {
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;
            }
            fwrite(&stu[i],sizeof(struct student),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
}

void print()
{
	FILE *fp;
	fp=fopen("stu_sort.dat","rb");
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
    fclose(fp);
}

int main()
{
	date_input();
	sort();
	print();
	return 0;
}


