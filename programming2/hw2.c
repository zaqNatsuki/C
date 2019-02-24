#include <stdio.h>

void add_minus(int,int,int [10][10],int [10][10]);
void multiply(int,int,int,int,int [10][10],int [10][10]);

int main(void)
{
    int i,j;
    int r1,c1,r2,c2;
    int num1[10][10],num2[10][10];
    //printf("program start\n");
    scanf("%d %d",&r1,&c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            scanf("%d",&num1[i][j]);
    }
    getchar();
    scanf("%d %d",&r2,&c2);
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
            scanf("%d",&num2[i][j]);
    }
    if(r1==r2&&c1==c2&&c1==r2)
    {
        add_minus(r1,c1,num1,num2);
        multiply(r1,c1,r2,c2,num1,num2);
    }
    else if(r1==r2&&c1==c2)
    {
        add_minus(r1,c1,num1,num2);
        printf("ERROR\n\n");
    }
    else if(c1==r2)
    {
        printf("\nERROR\n\nERROR\n\n");
        multiply(r1,c1,r2,c2,num1,num2);
    }
    else
        printf("\nERROR\n\nERROR\n\nERROR\n");
    return 0;
}

void add_minus(int row,int col,int num1[10][10],int num2[10][10])
{
    int num[row][col];
    int i,j,mode=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            if(mode==0)
                num[i][j]=num1[i][j]+num2[i][j];
            else if(mode==1)
                num[i][j]=num1[i][j]-num2[i][j];
        for(j=0;j<col;j++)
            printf("%d ",num[i][j]);
        printf("\n");
        if(i==row-1&&mode==0)
        {
            printf("\n");
            mode=1;
            i=-1;
        }
    }
    printf("\n");
    return;
}

void multiply(int r1,int c1,int r2,int c2,int num1[10][10],int num2[10][10])
{
    int i,j,k;
    int num[r1][c2];
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            num[i][j]=0;
    for(k=0;k<c1;k++)
        for(i=0;i<r1;i++)
            for(j=0;j<c2;j++)
                num[i][j]+=num1[i][k]*num2[k][j];
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
            printf("%d ",num[i][j]);
        printf("\n");
    }
    return;
}


