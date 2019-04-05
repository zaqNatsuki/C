#include <stdio.h>
#include <stdlib.h>

int isWalked(int,int,int,int**);
//y,x,maze,step,route,side_length
int walk(int,int,int**,int,int**,const int);

int main(void)
{
    int side_length,i,j,n=0;
    int **maze=NULL,**route=NULL;
    scanf("%d",&side_length);
    maze=(int**)malloc(sizeof(int*)*side_length);
    route=(int**)malloc(sizeof(int*)*(side_length*side_length));
    for(i=0;i<side_length;i++)
    {
        maze[i]=(int*)malloc(sizeof(int)*side_length);
        for(j=0;j<side_length;j++)
        {
            scanf("%d",&maze[i][j]);
            route[n]=(int*)malloc(sizeof(int)*2);
            n++;
        }
    }
    walk(1,1,maze,0,route,side_length);
    for(i=0;i<n;i++)
    {
        if(i<side_length) free(maze[i]);
        free(route[i]);
    }
    free(maze);free(route);
    return 0;
}

int walk(int y,int x,int** maze,int step,int** route,const int side_length)
{
    int wall=0,go=0,i,j;
    if(isWalked(y,x,step,route)==-1) return -1;
    else if(x>=side_length || x<=0 || y>=side_length || y<=0) return -1;
    else if(maze[y][x]==1) return -1;
    route[step][0]=y;route[step][1]=x;step++;
    if(y==side_length-2 && x==side_length-2)
    {
        for(i=0;i<side_length;i++)
        {
            for(j=0;j<side_length;j++)
            {
                if(isWalked(i,j,step,route)==-1) printf("# ");
                else if(maze[i][j]==-1) printf("* ");
                else printf("%d ",maze[i][j]);
            }
            puts("");
        }
        return 1;
    }
    go=walk(y+1,x,maze,step,route,side_length);
    if(go==-1) wall++; else return 1;
    go=walk(y-1,x,maze,step,route,side_length);
    if(go==-1) wall++; else return 1;
    go=walk(y,x-1,maze,step,route,side_length);
    if(go==-1) wall++; else return 1;
    go=walk(y,x+1,maze,step,route,side_length);
    if(go==-1) wall++; else return 1;
    if(wall==4)
    {
        maze[y][x]=-1;
        return -1;
    }
    return 1;
}

int isWalked(int y,int x,int step,int** route)
{
    int i;
    for(i=0;i<step;i++)
        if(route[i][0]==y && route[i][1]==x)
            return -1;
    return 1;
}



