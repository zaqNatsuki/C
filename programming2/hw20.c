#include <stdio.h>
#include <stdlib.h>

void initial(int**,int);
void play(int**,int**,int);
void step(int**,int,int);
void judge(int**,int**,int);

int main(void)
{
    int n,i,j;
    int **player1=NULL,**player2=NULL;
    scanf("%d",&n);
    player1=(int**)malloc(sizeof(int*)*n);
    player2=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    {
        player1[i]=(int*)malloc(sizeof(int)*n);
        player2[i]=(int*)malloc(sizeof(int)*n);
    }
    initial(player1,n);
    initial(player2,n);
    play(player1,player2,n);
    for(i=0;i<n;i++)
    {
        free(player1[i]);
        free(player2[i]);
    }
    free(player1);free(player2);
    return 0;
}

void initial(int **player,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&player[i][j]);
            getchar();
        }
    }
    return;
}

void play(int** p1,int** p2,int n)
{
    int *bingo=NULL,i,j,m=0;
    char c='1';
    bingo=(int*)malloc(sizeof(int)*(n*n));
    while(1)
    {
        scanf("%d",&bingo[m++]);
        if((c=getchar())=='\n') break;
    }
    for(i=0;i<m;i++)
    {
        step(p1,n,bingo[i]);
        step(p2,n,bingo[i]);
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",p1[i][j]);
        }
        puts("");
    }*/
    free(bingo);
    judge(p1,p2,n);
    return;
}

void step(int** p,int n,int bingo)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(p[i][j]==bingo)
                p[i][j]=0;
    return;
}

void judge(int** p1,int** p2,int n)
{
    int i,j,line[2],time[6];
    line[0]=line[1]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++) time[j]=0;
        for(j=0;j<n;j++)
        {
            if(p1[i][j]==0) time[0]++;
            if(p2[i][j]==0) time[1]++;
            if(p1[j][i]==0) time[4]++;
            if(p2[j][i]==0) time[5]++;
            if(i==0&&p1[j][j]==0) time[2]++;
            if(i==0&&p2[j][j]==0) time[3]++;
            if(i==n-1&&p1[i-j][j]==0) time[2]++;
            if(i==n-1&&p2[i-j][j]==0) time[3]++;
        }
        if(time[0]==n) line[0]++;if(time[2]==n) line[0]++;if(time[4]==n) line[0]++;
        if(time[1]==n) line[1]++;if(time[3]==n) line[1]++;if(time[5]==n) line[1]++;
    }
    if(line[0]==line[1]) printf("Draw %d\n",line[0]);
    else
        line[0]>line[1]?printf("Player1 wins %d, Player2 loses %d\n",line[0],line[1]):
            printf("Player2 wins %d, Player1 loses %d\n",line[1],line[0]);
    return;
}


