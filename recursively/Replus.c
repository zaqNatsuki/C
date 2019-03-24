#include <stdio.h>

int Replus(int);

int main(void)
{
    int n,sum;
    scanf("%d",&n);
    sum=Replus(n);
    printf("%d\n",sum);
    return 0;
}

int Replus(int n)
{
    if(n==1)
        return 1;
    else
        return Replus(n-1)+n;
}
