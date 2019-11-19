#define MAX3
#defineStatusint#defineHUMAN_WIN0//人取得了胜利
#defineDRAW1//平局
#definePLAYING2//没有决出胜负，正在进行游戏
#defineCOMPUTER_WIN3//电脑取得了胜利
#defineHUMAN0//人
#defineCOMPUTER1//机器
#defineEMPTY2//空
#defineFALSE0//假
#define TRUE1//真
#include<stdio.h>
#include"malloc.h" //记录一步棋所需的所有信息：行数，列数，判断值
typedefstruct
{   intcolumn;
    introw;
    intval;
}
    Nodes;
    intboard[MAX][MAX];//InitBoard初始化棋盘
StatusInitBoard()
{introw,column;
    for(row=0;row<MAX;row++)
        for(column=0;column<MAX;column++)
        {
            board[row][column]=EMPTY;
            return TRUE;
        }
} //PostionIsEmpty判断在棋盘上在给定的置是否为空
StatusPositionIsEmpty(introw,intcolumn)
{   if(board[row][column]==2)
        return TRUE;
    else
        return FALSE;
}
//Place在指定的地方落子
StatusPlace(introw,intcolumn,intpiece)
{   board[row][column]=piece;
    return TRUE;
}
//BoardIsFull判断棋盘是否己满S
tatusBoardIsFull()
{ inti=0,j=0;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
        {   if(board[i][j]==2)
            return FALSE;
        }
    return TRUE;
}
//IsWin判断是否有一方己经胜利
StatusIsWin(intside)
{   introw,column;//判断一行
    for(row=0;row<MAX;row++)
        {   for(column=0;column<MAX;column++)
            if(board[row][column]!=side) break;
            if(column>=MAX) returnTRUE;
        } //判断一列
    for(column=0;column<MAX;column++)
    {   for(row=0;row<MAX;row++)
        if(board[row][column]!=side) break;
        if(row>=MAX) return TRUE;
    }
//判断主对角线
    if(board[1][1]== side&&board[2][2]==side&&board[0][0] ==side) return TRUE; //判断副对角线
    if(board[0][2]== side&&board[1][1]==side&&board[2][0] ==side) return TRUE;
    return FALSE; }
//PositonValue返回落子后的状态有四种状态在ConstNum.h中定义COMPUTER_WIN,HUMAN_WIN,DRAW,PLAYING
StatusPostionValue()
{
    return IsWin(COMPUTER)?COMPUTER_WIN:(IsWin(HUMAN)?HUMAN_WIN:(BoardIsFull()?DRAW:PLAYING));
}
//BestMovement判断最佳落子位置,采用递归，求出最佳位置
NodesBestMovement(intside)
{   intopp;//对手
    Nodesnodes,node2;//nodes记录当前最佳位置
    node2//返回最佳位置
    intsimpleEval;//记当中间结果
    intbestRow=0,row;
    intbestColumn=0,column;
    intvalue; //判断是否游戏己经结束
    if((simpleEval=PostionValue())!=PLAYING)
    { node2.row=0;
    node2.column=0;
    node2.val=simpleEval;
    return node2;
    }
    if(side==COMPUTER)
        {
            opp=HUMAN;
            value=HUMAN_WIN;
    }
    else
    {
        opp=COMPUTER;
        value=COMPUTER_WIN;
    }
    for(row=0;row<MAX;row++)
        for(column=0;column<MAX;column++)
            if(PositionIsEmpty(row,column))
            { Place(row,column,side);
            nodes=BestMovement(opp);
            Place(row,column,EMPTY);//到更好的位置，更新信息
            if((side==COMPUTER&&nodes.val>value)||(side==HUMAN &&nodes.val<value))
                {   value=nodes.val;
                    bestRow=row;
                    bestColumn=column;
                }
            }
    node2.row=bestRow;
    node2.column=bestColumn;
    node2.val=value;
    returnnode2;
    }   //Print打印出当前棋盘状态
StatusPrint()
{
    introw,column;
    for(row=0;row<MAX;row++)
        for(column=0;column<MAX;column++)
        { if(board[row][column]==2) printf("^");
        else if(board[row][column]==1) printf("X");
        else printf("O");
        if((column!=0)&&(column%2==0))
            printf("\n");
        }
    return TRUE;
}
intmain(void)
{ NodesplayNode;
    intfirst,a,b,result,opera;//first决定谁先下第一步棋。
    result记录每下一步棋后的结果
    while(TRUE)
    { while(TRUE)
        { printf("请选择你要进行的操作：\n");
        printf("1：开局\n");
        printf("2:退出\n");
        scanf("%d",&opera);
        if(opera==1) break;
        if(opera==2) return TRUE;
            printf("你的输入有误，请重新输入\n");
        }
InitBoard();
    while(TRUE)
    {    printf("请决定人机对战时谁先走第一步？0：人1：电脑");
        scanf("%d",&first);
        if(first==0||first==1)
        { break;
        }
        printf("输入错误，请重新选择\n\n");
    }
    printf("人的棋子为O，电脑的棋子X,空位用^表示\n");
    if(first==0)
    { while(TRUE)
        { while(TRUE)
            { printf("请输入你落子所在的行数，列数（格式：a,b(a,b 在0~2之间))：");
              scanf("%d,%d",&a,&b);
               if(a>=0&&a<MAX&&b>=0&&b<=MAX&& PositionIsEmpty(a,b))
                break;
               printf("你输入的位置不合法，请重新输入：\n\n");
               }
    Place(a,b,HUMAN);
    Print();//下一步棋后打印出棋盘状态，并判断是否结束，如 结束，则跳出
    if((result=PostionValue())!=PLAYING) break;
        playNode=BestMovement(COMPUTER);
        Place(playNode.row,playNode.column,COMPUTER);
    printf("\n电脑落子后的棋盘为:\n");
    Print();////下一步棋后打印出棋盘状态，并判断是否结束， 如结束，则跳出
    if((result=PostionValue())!=PLAYING)
        break;
    }
    }
    else if(first==1){ while(TRUE)
    { printf("\n电脑落子后棋盘状态为\n");
    playNode=BestMovement(COMPUTER);
    Place(playNode.row,playNode.column,COMPUTER);
    Print();//下一步棋后打印出棋盘状态，并判断是否结束，如 结束，则跳出
    if((result=PostionValue())!=PLAYING) break;
    while(TRUE)
    { printf("请输入你落子所在的行数，列数（格式：a,b(a,b 在0~2之间))：");
        scanf("%d,%d",&a,&b);
        if(a>=0&&a<MAX&&b>=0&&b<=MAX&& PositionIsEmpty(a,b)) break;
        printf("你输入的位置不合法，请重新输入：\n\n");
    }
    Place(a,b,HUMAN);
    Print();//下一步棋后打印出棋盘状态，并判断是否结束，如 结束，则跳出
    if((result=PostionValue())!=PLAYING) break;
    }
    }
    if(result==COMPUTER_WIN) printf("哈哈，你输了！\n\n");
    elseif(result==HUMAN_WIN) printf("恭喜，你赢了！\n\n");
    else printf("平局！\n\n");
    }
    return0;
}
