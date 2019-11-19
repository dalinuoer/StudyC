#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct student)
struct student
{
    long num;
    float score;
    struct student *next;
};
int n=0;
struct student *creat(void)
{
    struct student *insert(struct student *head,struct student *stud);
    struct student *head,*p;
    p=(struct student *)malloc(LEN);
    scanf("%ld,%f",&p->num,&p->score);
    head=NULL;
    while(p->num!=0)
    {
        head=insert(head,p);
        p=(struct student *)malloc(LEN);
        scanf("%ld,%f",&p->num,&p->score);
    }
    free(p);
    return(head);
}

void print(struct student *head)
{
    struct student *p;
    p=head;
    if(head!=NULL)
    {
        printf("\nNow,these %d records are:\n",n);
        do
        {
            printf("%ld %5.1f\n",p->num,p->score);
            p=p->next;
        }while(p!=NULL);
    }
	else
		printf("\nSorry! No records now!\n");
}

struct student *insert(struct student *head,struct student *stud)
{
    struct student *p0,*p1,*p2;
    p1=head;
    p0=stud;
    if(head==NULL)
    {
        head=p0;
        p0->next=NULL;
    }
    else
    {
        while((p0->num>p1->num)&&(p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num<=p1->num)
        {
            if(head==p1)
                head=p0;
            else
                p2->next=p0;
            p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    n++;
    return(head);
}

struct student *del(struct student *head,long num)
{
   struct student *p1,*p2;
   if(head==NULL)
   {
       printf("List is null!\n");
       return(head);
   }
   p1=head;
   while(num!=p1->num&&p1->next!=NULL)
   {
       p2=p1;
       p1=p1->next;
   }
   if(num==p1->num)
   {
       if(p1==head)
            head=p1->next;
       else
            p2->next=p1->next;
       printf("Deleted:%ld\n",num);
       n=n-1;
       free(p1);
   }
   else
        printf("%ld not been found!\n",num);
   return(head);
}

int main()
{
	struct student *head,*p;
	long del_num;
	int choice;
	printf("Please input records:\n");
	head=creat();
	print(head);
	printf("1.insert\t2.delete\t0.exit\n");
	choice=-1;
	printf("Please choose:");
	scanf("%d",&choice);
	getchar();
	switch(choice)
	{
        case 1:                                         //insert
                printf("Please input num and score:");
                p=(struct student *)malloc(LEN);
                scanf("%ld,%f",&p->num,&p->score);
                head=insert(head,p);
                printf("Inserted:%ld\n",p->num);
                print(head);
                break;
        case 2:                                         //delete
                printf("Please input num:");
                scanf("%ld",&del_num);
                head=del(head,del_num);
                print(head);
	}
	return 0;
}



