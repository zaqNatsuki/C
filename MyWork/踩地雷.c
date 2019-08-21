#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int** setting(int*,int*);
void setbomb(int**,int,int,int);
void display(int**,int,int,int);
int isWin(int**,int,int);
int action(int**,int,int);
int isBomb(int**,int,int,int,int);
void freeAll(int**,int);

int main(void)
{
    int **map=NULL,row,col,win=0,lose=0,info=0;
    char mode[10];
    srand(time(NULL));
    map=setting(&row,&col);
    while(1)
    {
        display(map,row,col,info);
        if(info==-1)
        {
            printf("BOOM!!! GameOver!!! You Lose!!\n");
            break;
        }
        if(isWin(map,row,col)==1)
        {
            printf("Congratulation !! You Win!!\n");
            break;
        }
        info=action(map,row,col);
    }
    freeAll(map,row);
    return 0;
}

int** setting(int *row,int *col)
{
    int **map,i,bomb;
    char mode[10];
    printf("%-7s=%-6sbomb=10\n","easy","8*8");
    printf("%-7s=%-6sbomb=40\n","normal","16*16");
    printf("%-7s=%-6sbomb=99\n","hard","30*16");
    printf("choose mode:");
    while(1)
    {
        scanf("%s",mode);
        if(strcmp("easy",mode)==0)
        {
            *row=*col=8;
            bomb=10;
            break;
        }
        else if(strcmp("normal",mode)==0)
        {
            *row=*col=16;
            bomb=40;
            break;
        }
        else if(strcmp("hard",mode)==0)
        {
            *row=16;
            *col=30;
            bomb=99;
            break;
        }
        else
        {
            printf("please input easy,normal or hard:");
        }
    }
    map=(int**)malloc(sizeof(int*)*(*row));
    for(i=0;i<*row;i++) map[i]=(int*)malloc(sizeof(int)*(*col));
    setbomb(map,*row,*col,bomb);
    return map;
}

void setbomb(int **map,int row,int col,int bomb)
{
    int i,j,nb=0,x,y;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            map[i][j]=-1;
    while(nb<bomb)
    {
        x=(rand()%col);
        y=(rand()%row);
        //printf("%d,%d\n",x,y);
        if(map[y][x]!=-2)
        {
            map[y][x]=-2;
            nb++;
        }
    }
    return;
}

void display(int **map,int row,int col,int info)
{
    int i,j;
    system("cls");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(map[i][j]==-1) printf(" _");
            else if(map[i][j]==-2) printf(" *");
            else if(map[i][j]==-3||map[i][j]==-4) printf(" !");
            else if(map[i][j]==0) printf("  ");
            else if(map[i][j]==-10) printf(" X");
            else printf("%2d",map[i][j]);
        }
        printf("\n");
    }
    if(info==-3) printf("Plz cancel tag first.\n");
    else if(info==-4) printf("Plz don't step on illegal place.\n");
    return;
}

int isWin(int **map,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            if(map[i][j]==-1||map[i][j]==-3) return 0;
    return 1;
}

int action(int **map,int row,int col)
{
    int i,j,act=3,guess_row,guess_col,result=0;
    while(act==3)
    {
        printf("input col:");
        scanf("%d",&guess_col);
        while(!(guess_col<col+1 && guess_col>0))
        {
            printf("wrong input.Plz input again:");
            scanf("%d",&guess_col);
        }
        printf("input row:");
        scanf("%d",&guess_row);
        while(!(guess_row<row+1 && guess_row>0))
        {
            printf("wrong input.Plz input again:");
            scanf("%d",&guess_row);
        }
        printf("col=%d,row=%d",guess_col,guess_row);
        printf("1.step 2.tag 3.cancel\ninput action:");
        scanf("%d",&act);
    }
    guess_col-=1;guess_row-=1;        //顯示邊界為1~n,程式內部為0~n-1
    if(act==1)
    {
        //system("cls");
        result=isBomb(map,row,col,guess_row,guess_col);
        if(result==-1)
        {
            map[guess_row][guess_col]=-10;
            return -1;
        }
        return result;
    }
    else if(act==2)
    {
        if(map[guess_row][guess_col]>=0) return -4;
        if(map[guess_row][guess_col]==-3||map[guess_row][guess_col]==-4)
            map[guess_row][guess_col]+=2;//將值重新變回-1-2
        else
            map[guess_row][guess_col]-=2;//將值變成-3-4已顯示成標記(-3=還沒被猜過的位置 -4=炸彈的位置)
    }
    return 0;
}

void freeAll(int **map,int row)
{
    int i;
    for(i=0;i<row;i++) free(map[i]);
    free(map);
    return;
}

int isBomb(int **map,int row,int col,int gr,int gc)
{
    int i,j,bomb=0;
    if(gr<0||gr>=row||gc<0||gc>=col) return -2;         //超過邊界，主要用在遞迴式的判斷
    if(map[gr][gc]==-2||map[gr][gc]==-4) return -1;     //踩到炸彈
    if(map[gr][gc]==-3) return -3;                      //踩到標記
    if(map[gr][gc]!=-1) return -4;                      //空白or已顯示的地方
    for(i=-1;i<2;i++)
        for(j=-1;j<2;j++)
        {
            if(gr+i<0||gr+i>=row||gc+j<0||gc+j>=col) continue;
            if(map[gr+i][gc+j]==-2||map[gr+i][gc+j]==-4) bomb++;
        }
    map[gr][gc]=bomb;
    if(bomb!=0) return bomb;
    else
    {
        for(i=-1;i<2;i++)
            for(j=-1;j<2;j++)
                isBomb(map,row,col,gr+i,gc+j);
    }
    return 1;
}






