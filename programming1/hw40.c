#include <stdio.h>

int isPrime(int);           //質數判斷
void getAnswer(int);        //因數判斷+輸出
int getClass(int);          //取得階層值

int main(void)
{
    int n=0;
    char c='0';
    //printf("Program Start\n");
    scanf("%d",&n);
    while((c=getchar())!=EOF && c!='\n')
    {
        printf("E\n");
        return 0;
    }
    if(n>0&&n<1000)
    {
        getAnswer(n);
    }
    else
    {
        printf("E\n");
    }
    return 0;
}

void getAnswer(int n)
{
    int i,j,num=0;
    int p=0,f=0,total=0;
    num=n;
    for(i=2;i<=num;i++)
    {
        p=0;
        if(num%i==0)
        {
            p=isPrime(i);
        }
        if(p==1)
        {
            f=getClass(i);
            total+=f;
            printf("%d,%d\n",i,f);
        }
    }
    printf("%d\n",total);
    return;
}

int isPrime(int n)
{
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int getClass(int n)
{
    int i=0,f=1;
    for(i=2;i<=n;i++)
    {
        f*=i;
    }
    return f;
}
