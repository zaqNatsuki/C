#include <stdio.h>

int ReMultiply(int,int);

int main(void)
{
    int total,n,time=0;
    scanf("%d %d",&n,&time);
    total=ReMultiply(n,time);
    printf("%d\n",total);
    return 0;
}

int ReMultiply(int n,int time)
{
    if(time==1)
        return n;
    else
        return ReMultiply(n,time-1)*n;
}
