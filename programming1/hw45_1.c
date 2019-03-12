#include <stdio.h>

void compute(int*);
int horizontal(int*,int,int);
int vertical(int*,int,int);
int Lup_Rdown(int*,int,int);
int Rup_Ldown(int*,int,int);
void ans(int,int);
int position[50][2];
int number=0;

int main(void)
{
    int place[10][10]={0};
    int i,j,k;
    //printf("Program Start\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&place[i][0]);
        for(j=1;j<10;j++)
            scanf("%d",&place[i][j]);
    }
    compute(place);
    for(i=0;i<number;i++)
        printf("%d %d\n",position[i][0],position[i][1]);
    return 0;
}

void compute(int* place)
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            //if(number==6)return;
            if(horizontal(place,i,j))continue;
            if(vertical(place,i,j))continue;
            if(Rup_Ldown(place,i,j))continue;
            if(Lup_Rdown(place,i,j))continue;
        }
    }
    return;
}

int horizontal(int* place,int row,int column)
{
    int i,sum=0,p=0;
    int li[5];
    if(column>5)return 0;
    for(i=0;i<5;i++)
    {
        li[i]=*(place+row*10+column+i);
        sum+=li[i];
        if(li[i]==0)
        {
            p=i+column;
        }
    }
    if(sum==4)
    {
        ans(row,p);
        *(place+row*10+p)=-1;
        return 1;
    }
    return 0;
}

int vertical(int* place,int row,int column)
{
    int i,sum=0,j,p;
    int li[5];
    if(row>5)return 0;
    for(i=0;i<5;i++)
    {
        li[i]=*(place+(row+i)*10+column);
        sum+=li[i];
        if(li[i]==0)
        {
            p=row+i;
        }
    }
    if(sum==4)
    {
        ans(p,column);
        *(place+p*10+column)=-1;
        return 1;
    }
    return 0;
}

int Lup_Rdown(int* place,int row,int column)
{
    int i,sum=0,prow,pcolumn;
    int li[5];
    if(row>5 || column>5)return 0;
    for(i=0;i<5;i++)
    {
        li[i]=*(place+row*10+column+i*11);
        sum+=li[i];
        if(li[i]==0)
        {
            prow=row+i;
            pcolumn=column+i;
        }
    }
    if(sum==4)
    {
        ans(prow,pcolumn);
        *(place+prow*10+pcolumn)=-1;
        return 1;
    }
    return 0;
}

int Rup_Ldown(int* place,int row,int column)
{
    int i,sum=0,prow,pcolumn;
    int li[5];
    if(row>5 || column<4)return 0;
    for(i=0;i<5;i++)
    {
        li[i]=*(place+column+row*10+i*9);
        sum+=li[i];
        if(li[i]==0)
        {
            prow=row+i;
            pcolumn=column-i;
        }
    }
    if(sum==4)
    {
        ans(prow,pcolumn);
        *(place+prow*10+pcolumn)=-1;
        return 1;
    }
    return 0;
}

void ans(int row,int column)
{
    int i,j;
    if(number==0)
    {
        position[0][0]=row;
        position[0][1]=column;
    }
    //printf("...%d %d %d\n",row,column,number);
    if(row==-1 && column==-1)return ;
    for(i=0;i<number;i++)
    {
        if(row==position[i][0] && column==position[i][1])
            return;
    }
    for(i=0;i<number;i++)
    {
        if(row<position[i][0])
        {
            for(j=number;j>i;j--)
            {
                position[j][0]=position[j-1][0];
                position[j][1]=position[j-1][1];
            }
            position[i][0]=row;
            position[i][1]=column;
        }
        else if(row==position[i][0])
        {
            if(column<position[i][1])
            {
                for(j=number;j>i;j--)
                {
                    position[j][0]=position[j-1][0];
                    position[j][1]=position[j-1][1];
                }
                position[i][0]=row;
                position[i][1]=column;
            }
            else if(column>position[i][1] && (row<position[i+1][0] || (position[i+1][0]==0&& position[i+1][1]==0)))
            {
                for(j=number;j>i+1;j--)
                {
                    position[j][0]=position[j-1][0];
                    position[j][1]=position[j-1][1];
                }
                position[i+1][0]=row;
                position[i+1][1]=column;
            }
        }
        else if(row>position[number-1][0])
        {
            position[number][0]=row;
            position[number][1]=column;
        }
    }
    number++;
    return ;
}
