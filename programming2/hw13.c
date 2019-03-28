#include <stdio.h>

void initialize(int[][20]);
void act_print(int,int[][2]);
int act_move(int[][20],int[][2],int,int);
void drawMap(int[][20]);

int main(void)
{
    int game_map[20][20],snake[20][2];
    int act_style[500],dir=0,i,n=0,snake_len=1;    //snake_len=-1代表結束
    initialize(game_map);
    snake[0][0]=snake[0][1]=9;
    while (1)
    {
        scanf("%d",&act_style[n]);
        n++;
        if(act_style[n-1]==-1) break;
    }
    for(i=0;i<n;i++)
    {
        if(act_style[i]==5) snake_len=act_move(game_map,snake,dir,snake_len);
        else if(act_style[i]==0||act_style[i]==-1) act_print(snake_len,snake);
        else dir=act_style[i];
        if(snake_len==-1)
        {
            //printf("GameOver\n");
            break;
        }
    }
    //drawMap(game_map);
    return 0;
}

void initialize(int map[][20])  //初始化盤面,設置水果、牆壁
{
    int n,i,j,x,y;
    scanf("%d",&n);
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
        {
            if(i==0||i==19||j==0||j==19) map[i][j]=-8;
            else if(i==9&&j==9) map[i][j]=1;
            else map[i][j]=0;
        }
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&y,&x);
        map[y][x]=-1;
    }
    return;
}

void act_print(int len,int snake[][2])
{
    int i;
    printf("%d\n",len);
    for(i=0;i<len;i++)
        printf("%d %d\n",snake[i][0],snake[i][1]);
    return;
}

int act_move(int map[][20],int snake[][2],int dir,int snake_len)
{
    //1上2下3左4右
    int i,newY,newX,thing;
    newY=snake[0][0];
    newX=snake[0][1];
    if(dir==1) newY--;
    else if(dir==2) newY++;
    else if(dir==3) newX--;
    else newX++;
    thing=map[newY][newX];
    if(thing==0 || thing==-1)
    {
        if(thing==-1) snake_len++;
        //如果下一格是空白,就把最後的地方補0.
        else map[snake[snake_len-1][0]][snake[snake_len-1][1]]=0;
        for(i=snake_len-1;i>0;i--)
        {
            snake[i][0]=snake[i-1][0];
            snake[i][1]=snake[i-1][1];
        }
        snake[0][0]=newY;
        snake[0][1]=newX;
        for(i=0;i<snake_len;i++) map[snake[i][0]][snake[i][1]]=i+1;
        return snake_len;
    }
    //GameOver
    else
    {
        act_print(snake_len,snake);
        return-1;
    }
}

void drawMap(int map[][20])
{
    int i,j;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
            printf("%2d",map[i][j]);
        printf("\n");
    }
    return;
}

