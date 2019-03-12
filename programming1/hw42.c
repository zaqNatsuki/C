#include <stdio.h>
#include <math.h>

int check(int,int,int,int);
void add(int,int,int,int,int*,int*);
void mutiple(int,int,int,int,int*,int*);
void simple(int*,int*);
void out(int,int);

int main(void)
{
    int n1,n2;              //分子
    int d1,d2;              //分母
    /*int* sumN,*sumD;        //相加
    int* timeN,*timeD;      //相乘*/
    int sumN,sumD;
    int timeN,timeD;
    scanf("%d/%d",&n1,&d1);
    scanf("%d/%d",&n2,&d2);
    add(n1,d1,n2,d2,&sumN,&sumD);
    mutiple(n1,d1,n2,d2,&timeN,&timeD);
    return 0;
}

int check(int n1,int d1,int n2,int d2)
{
    if(n1==0 || n2==0 || d1==0 || d2==0)
        return 0;
    return 1;
}

void add(int n1,int d1,int n2,int d2,int* sumN,int* sumD)
{
    int error=0;            //判斷輸入
    if((error=check(n1,d1,n2,d2))==0)
    {
        printf("ERROR\n");
        return;
    }
    *sumN=n1*d2+n2*d1;
    *sumD=d1*d2;
    if(*sumN==0)
    {
        printf("0\n");
        return;
    }
    else
    {
        simple(sumN,sumD);
        out(*sumN,*sumD);
    }
    return;
}

void mutiple(int n1,int d1,int n2,int d2,int* timeN,int* timeD)
{
    int error=0;            //判斷輸入
    if((error=check(n1,d1,n2,d2))==0)
    {
        printf("ERROR\n");
        return;
    }
    *timeN=n1*n2;
    *timeD=d1*d2;
    simple(timeN,timeD);
    out(*timeN,*timeD);
}

void simple(int* n,int* d)
{
    int temp=0,nn,dd;
    if(abs(*n)>=abs(*d))
    {
        nn=abs(*n);
        dd=abs(*d);
    }
    else
    {
        nn=abs(*d);
        dd=abs(*n);
    }
    if(*d<0)
    {
        *n=-(*n);
        *d=-(*d);
    }
    while(dd!=0)
    {
        temp=dd;
        dd=nn%dd;
        nn=temp;
    }
    *n=*n/nn;
    *d=*d/nn;
    return;
}

void  out(int n,int d)
{
    if(abs(n)>d)
    {
        if(n>0)
        {
            printf("%d(%d/%d)\n",n/d,n%d,d);
        }
        else
        {
            n=-n;
            printf("-%d(%d/%d)\n",n/d,n%d,d);
        }
    }
    else if(abs(n)<d)
    {
        printf("%d/%d\n",n,d);
    }
    else
    {
        printf("1\n");
    }
    return;
}
