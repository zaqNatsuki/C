#include <stdio.h>

int initial(int,int,int[][9]);
//walk=>row,column,step,city,route,minCost,nowCost,ROW,COLUMN
int walk(int,int,int[][9],int,int[][2],int[],int,const int,const int);
int is_walked(int,int,int,int[][2]);

int main(void)
{
    int i,j,row,column,nowCost=0,step=0,x=0,y=0;
    int route[81][2],minCost[1];
    char c;
    scanf("%d",&row);
    scanf("%d",&column);
    int number_city[9][9];
    minCost[0]=initial(row,column,number_city);
    walk(y,x,number_city,step,route,minCost,nowCost,row,column);
    printf("%d\n",minCost[0]);
    return 0;
}

int initial(int row,int column,int city[][9])
{
    int i,j,min=0;
    for(i=0;i<row;i++)
        for(j=0;j<column;j++)
        {
            scanf("%d",&city[i][j]);
            if(i==0 || j==column-1) min+=city[i][j];
        }
    return min;
}

int is_walked(int y,int x,int step,int route[][2])
{
    int i;
    for(i=0;i<step;i++)
        if(route[i][0]==y && route[i][1]==x) return -1;
    return 1;
}

int walk(int y,int x,int city[][9],int step,int route[][2],int minCost[],int nowCost,const int row,const int column)
{
    if(is_walked(y,x,step,route)==-1) return nowCost;
    else if(y>=row || y<0 || x<0 || x>=column) return nowCost;
    route[step][0]=y;route[step][1]=x;
    step++;
    nowCost+=city[y][x];
    if(nowCost>=minCost[0])
        return nowCost-city[y][x];
    else
    {
        if(y==row-1 && x==column-1)
        {
            minCost[0]=nowCost;
            return nowCost-city[y][x];
        }
        else
        {
            walk(y,x+1,city,step,route,minCost,nowCost,row,column);
            walk(y+1,x,city,step,route,minCost,nowCost,row,column);
            walk(y,x-1,city,step,route,minCost,nowCost,row,column);
            walk(y-1,x,city,step,route,minCost,nowCost,row,column);
        }
    }
}

