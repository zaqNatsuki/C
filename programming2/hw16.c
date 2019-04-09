#include <stdio.h>
#include <string.h>

void initial(int[][3][3]);
void print(int[][3][3]);
void play(int,char,int[][3][3]);
void act_rotate(char,int[3][3]);
void act_U(int,int[][3][3]);
void act_L(int,int[][3][3]);
void act_UC(char,int[][3][3]);

int main(void)
{
    int cube[6][3][3];
    char act,loc,c,command[3];
    initial(cube);
    //print(cube);
    while(1)
    {
        scanf("%s",command);
        if(strcmp(command,"-1")==0) break;
        play(*(command)-'0',*(command+1),cube);
    }
    print(cube);
    return 0;
}

void initial(int cube[][3][3])
{
    int i,j,k,n;
    for(i=0;i<6;i++)
    {
        n=(i+1)*10;
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                if(i==4) cube[i][2-j][2-k]=n;
                else cube[i][j][k]=n;
                n++;
            }
        }
    }
    //print(cube);
    return;
}

void print(int cube[][3][3])
{
    int i,j,k;
    /*for(i=0;i<6;i++)
    {*/
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                printf("%d ",cube[1][j][k]);
            }
            printf("\n");
        }
        /*printf("\n");
    }*/
    return;
}

void play(int loc,char act_command,int cube[][3][3])
{
    int i;
    if(loc==19)
    {
        act_rotate(act_command,cube[1]);
        act_UC(act_command,cube);
        return;
    }
    if(act_command=='U')
    {
        act_U(loc,cube);
    }
    else if(act_command=='D')
    {
        for(i=0;i<3;i++)
            act_U(loc,cube);
    }
    else if(act_command=='L')
    {
        act_L(loc,cube);
    }
    else if(act_command=='R')
    {
        for(i=0;i<3;i++)
            act_L(loc,cube);
    }
    return;
}

void act_U(int loc,int cube[][3][3])
{
    int i,col,temp;
    col=loc%3;
    if(col==0) act_rotate('L',cube[0]);
    else if(col==2) act_rotate('R',cube[2]);
    for(i=0;i<3;i++)
    {
        temp=cube[1][i][col];
        cube[1][i][col]=cube[3][i][col];
        cube[3][i][col]=cube[4][2-i][2-col];
        cube[4][2-i][2-col]=cube[5][i][col];
        cube[5][i][col]=temp;
    }
    return;
}

void act_UC(char act,int cube[][3][3])
{
    int temp,i;
    if(act=='R')
    {
        for(i=0;i<3;i++)
        {
            temp=cube[0][i][2];
            cube[0][i][2]=cube[3][0][i];
            cube[3][0][i]=cube[2][2-i][0];
            cube[2][2-i][0]=cube[5][2][2-i];
            cube[5][2][2-i]=temp;
        }
    }
    else
    {
        for(i=0;i<3;i++)
            act_UC('R',cube);
    }
    return;
}

void act_L(int loc,int cube[][3][3])
{
    int i,row,temp;
    row=loc/3;
    if(row==0) act_rotate('R',cube[5]);
    else if(row==2) act_rotate('L',cube[3]);
    for(i=0;i<3;i++)
    {
        temp=cube[0][row][i];
        cube[0][row][i]=cube[1][row][i];
        cube[1][row][i]=cube[2][row][i];
        cube[2][row][i]=cube[4][row][i];
        cube[4][row][i]=temp;
    }
    return;
}

void act_rotate(char act,int cube[3][3])
{
    int temp,i;
    if(act=='R')
    {
        temp=cube[0][0];cube[0][0]=cube[2][0];cube[2][0]=cube[2][2];cube[2][2]=cube[0][2];cube[0][2]=temp;
        temp=cube[0][1];cube[0][1]=cube[1][0];cube[1][0]=cube[2][1];cube[2][1]=cube[1][2];cube[1][2]=temp;
    }
    else
    {
        for(i=0;i<3;i++) act_rotate('R',cube);
    }
    return;
}

