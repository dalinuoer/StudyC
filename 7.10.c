#include<stdio.h>
#include<string.h>
int main()
{
    int f1(char c);
    int longest_word(char str[]);
    int i;
    char str[81];
    printf("Please input a line:");
    gets(str);
    printf("The longest word is ");
    for(i=longest_word(str);f1(str[i]);i++)
        printf("%c",str[i]);
    printf("\n");
    return 0;
}

//求最长单词的函数
int f1(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return(1);
    else
        return(0);
}

int longest_word(char str[])
{
    int i,point,symbol=1,len=0,length=0,place=0;
    for(i=0;i<=strlen(str);i++)
    {
        if(f1(str[i]))
        {
            if(symbol)
            {
                point=i;
                symbol=0;
            }
            else
                len++;
        }
        else
        {
            symbol=1;
            if(len>=length)
            {
                length=len;
                place=point;
                len=0;
            }
        }
    }
    return(place);
}
















