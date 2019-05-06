#include <stdio.h>

#define PI 4

int compute(char*,int);

int main(void)
{
    int n,i,len,sum=0,peremeter=0;
    char c,detail[4];
    scanf("%d",&n);getchar();
    for(i=0;i<n;i++)
    {
        len=0;
        while(1)
        {
            c=getchar();
            if(c==' ') continue;
            else if(c=='\n') break;
            else detail[len++]=c;
        }
        peremeter=compute(detail,len);
        printf("%d\n",peremeter);
        sum+=peremeter;
    }
    printf("%d\n",sum);
    return 0;
}

int compute(char *detail,int len)
{
    int i,sum=0;
    switch(detail[0])
    {
        case 'C':
            return 2*(detail[1]-'0')*PI;
            break;
        case 'R':
            for(i=1;i<len;i++) sum+=detail[i]-'0';
            return 2*sum;
            break;
        case 'S':
            return (detail[1]-'0')*4;
            break;
        case 'T':
            for(i=1;i<len;i++) sum+=detail[i]-'0';
            return sum;
            break;
    }
}

