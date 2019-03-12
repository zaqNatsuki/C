#include <stdio.h>
#include <math.h>

void compute(int,int,int,int,int*,int*);

int main(void)
{
    int x1,y1,x2,y2;
    int meter=0,ar=0;
    //int *perimeter=&meter,*area=&ar;
    char c;
    while(1)
    {
        //printf("input four integers:");
        scanf("%d",&x1);
        if((c=getchar())!= ' ')break;   //只輸入-1便跳離
        scanf("%d %d %d",&y1,&x2,&y2);
        if(x1==x2 || y1==y2)
        {
            printf("Error\n");
            return 0;
        }
        compute(x1,y1,x2,y2,&meter,&ar);
    }
    printf("%d\n%d\n",ar,meter);
    return 0;
}

void compute(int x1,int y1,int x2,int y2,int *meter,int *ar)
{
    int newArea=0,newMeter=0;           //算出來的結果先存入新的變數再做比對
    int x,y;
    x=abs(x1-x2);
    y=abs(y1-y2);
    newArea=x*y;
    newMeter=2*(x+y);
    if(newArea>*ar)*ar=newArea;
    if(newMeter>*meter)*meter=newMeter;
    //printf("%d\n%d\n",newArea,newMeter);
    return;
}
