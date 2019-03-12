#include <stdio.h>

void draw(int,int);
void drawStar1(int);        //�y�V�k
void drawStar2(int);        //�y�V��
void drawStar3(int);        //�٧�

int main(void)
{
    int style=0,line=0;
    //printf("Program Start\n");
    scanf("%d",&style);
    scanf("%d",&line);
    draw(style,line);
    return 0;
}

void draw(int style,int line)
{
    if(style==1)
        drawStar1(line);
    else if(style==2)
        drawStar2(line);
    else if(style==3)
        drawStar3(line);
    return;
}

void drawStar1(int line)
{
    int mid=0,i,j;
    mid=(line+1)/2;
    for(i=1;i<line+1;i++)
    {
        if(i<=mid)
        {
            for(j=0;j<i;j++)
                printf("*");
        }
        else
        {
            for(j=0;j<line-i+1;j++)
                printf("*");
        }
        printf("\n");
    }
    return;
}

void drawStar2(int line)
{
    int mid=0,i,j;
    mid=(line+1)/2;
    for(i=1;i<line+1;i++)
    {
        if(i<=mid)
        {
            for(j=i;j<mid;j++)
                printf(".");
            for(j=0;j<i;j++)
                printf("*");
        }
        else
        {
            for(j=i;j>mid;j--)
                printf(".");
            for(j=line+1;j>i;j--)
                printf("*");
        }
        printf("\n");
    }
    return;
}

void drawStar3(int line)
{
    int mid=0,i,j,time=0;
    mid=(line+1)/2;         //�T�w��
    time=-1;               //*�n��X������
    for(i=1;i<line+1;i++)
    {
        if(i<=mid)
        {
            time+=2;
            for(j=i;j<mid;j++)
                printf(".");
            for(j=0;j<time;j++)
                printf("*");
        }
        else
        {
            time-=2;
            for(j=i;j>mid;j--)
                printf(".");
            for(j=0;j<time;j++)
                printf("*");
        }
        printf("\n");
    }
    return;
}


