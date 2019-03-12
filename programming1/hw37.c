#include <stdio.h>

void getInput(int[3][4]);
int isCorrect(int[3][4]);
int isClassTime(int);
void sameTime(int[3][4]);

int main(void)
{
    int lesson[3][4]={0};
    int isError=0;
    getInput(lesson);
    isError=isCorrect(lesson);
    if(isError==0)
        sameTime(lesson);
    else
        printf("-1\n");
    return 0;
}

void getInput(int lesson[3][4])
{
    int i=0;
    for(i=0;i<3;i++)
    {
        scanf("%d",&lesson[i][0]);
        scanf("%d",&lesson[i][1]);
        if(lesson[i][1]==1)
        {
            scanf("%d",&lesson[i][2]);
        }
        else if(lesson[i][1]==2)
        {
            scanf("%d",&lesson[i][2]);
            scanf("%d",&lesson[i][3]);
        }
        else
            scanf("%d",&lesson[i][2]);
    }
}

int isCorrect(int lesson[3][4])
{
    int isError=0,i=0;
    for(i=0;i<3;i++)
    {
        if(!(lesson[i][0]>999 && lesson[i][0]<10000))
            return -1;
        if(lesson[i][1]!=1 && lesson[i][1]!=2)
            return -1;
        if((isError=isClassTime(lesson[i][2]))==-1)
            return -1;
        if((isError=isClassTime(lesson[i][3]))==-1)
            return -1;
    }
    return 0;
}

int isClassTime(int ct)
{
    if(ct==0)
        return 0;
    if(ct>10 && ct<60)
    {
        if(ct%10==0)
            return -1;
        else
            return 0;
    }
    else
        return -1;
}

void sameTime(int lesson[3][4])
{
    int same=0,i,j,k,m;
    for(i=0;i<2;i++)
        for(j=2;j<4;j++)
        {
            if(lesson[i][j]==0)
                continue;
            for(k=i+1;k<3;k++)
                for(m=2;m<4;m++)
            {
                if(lesson[i][j]==lesson[k][m])
                {
                    same++;
                    printf("%d,%d,%d\n",lesson[i][0],lesson[k][0],lesson[i][j]);
                }
            }
        }
    if(same==0)
        printf("correct\n");
    return;
}
