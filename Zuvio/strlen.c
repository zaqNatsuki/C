#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("program start\n");
    int len=0,i=0;
    char a[10]="android";
    while(1)
    {
        if(*(a+i)!='\0')len++;
        else break;
        i++;
    }
    printf("%d\n",len);
    /*int id,s1,s2,s3;
    char a,b,c[10];
    scanf("%d %s %d %d %d",&id,c,&s1,&s2,&s3);
    printf("%d %s %d %d %d\n",id,c,s1,s2,s3);*/
    return 0;
}
