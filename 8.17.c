#include<stdio.h>
#include<string.h>
int strstr1(char *str1,char *str2)
{
    char *p,*b;
    int t=0,i;
    for(p=str1;p<str1+strlen(str1);p++)
    {
        if(*p==*str2)
        {
            for(i=0;i<strlen(str2);i++)
            {
                if(*(p+i)==*(str2+i))
                {
                    if(i==strlen(str2)-1)
                    {
                        t=1;
                        b=p;
                        break;
                    }
                }
                else
                {
                    t=0;
                    break;
                }
				if(t==1)break;
            }
        }
    }
    if(t) return(b-str1+1);
    else return(-1);
}

int main()
{
    char str1[100],str2[100];
    int a;
    printf("请输入第一个字符串：");
    scanf("%s",str1);
    printf("请输入第二个字符串：");
    scanf("%s",str2);
    a=strstr1(str1,str2);
    if(a==-1)
        printf("第一个和第二个字符串没有相同地方。");
    else
        printf("是从第%d位开始相同。",a);
    return 0;
}
