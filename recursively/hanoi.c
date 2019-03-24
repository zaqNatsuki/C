#include <stdio.h>

void hanoi(int,char,char,char);

int main(void)
{
    int n;
    scanf("%d",&n);
    hanoi(n,'B','A','C');
    return 0;
}

void hanoi(int n,char buffer,char src,char dst)
{
    printf("hanoi(%d %c %c %c)\n",n,buffer,src,dst);
    if(n==1)
        printf("move disk 1 from %c to %c\n",src,dst);
    else
    {
        hanoi(n-1,dst,src,buffer);
        printf("move disk %d from %c to %c\n",n,src,dst);
        hanoi(n-1,src,buffer,dst);
    }
    return;
}
