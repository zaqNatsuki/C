#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Password_First(char*);
void Password_Second(char*);
int int_inverse(int);
int int_pow(int);
int is_digit(char*);

int main(void)
{
    int i=0;
    char c,x[300],y[300];
    scanf("%[^\n]",x);
    c=getchar();
    scanf("%[^\n]",y);
    Password_First(x);
    Password_Second(y);
    i++;

    return 0;
}

void Password_First(char* x)
{
    int n=0,sum=0,time=0;
    char *p[50];
    p[0]=strtok(x," ");
    while(p[time]!=NULL)
    {
        n=is_digit(p[time]);
        if(n!=-1) sum+=int_inverse(n);
        time++;
        p[time]=strtok(NULL," ");
    }
    if(sum>=1000) printf("%d",sum%=10000);
    else printf("0%d",sum);
    return;
}

void Password_Second(char* x)
{
    int i,j,same,len=strlen(x);
    int freq[len/2],dif=0;
    char c;
    for(i=0;i<len;i++)
    {
        c=*(x+i);
        if(c=='.'||c==' ') continue;
        else if(c<='9'&&c>='0')
        {
            freq[dif]=c-'0';
            dif++;
            continue;
        }
        same=1;
        for(j=i+1;j<len;j++)
        {
            if(c==*(x+j))
            {
                *(x+j)='.';
                same++;
            }
        }
        freq[dif]=same;
        dif++;
    }
    for(i=0;i<dif;i++)
        if(freq[i]<10)
            printf("%d",freq[i]);
    return;
}

int int_inverse(int num)
{
    int big=1,len=0,i,sum=0;
    while(big<=num)
    {
        big*=10;
        len++;
    }
    for(i=0;i<len;i++)
    {
        sum+=(num%10)*int_pow(len-i-1);
        num/=10;
    }
    return sum;
}

int int_pow(int time)
{
    int i,x=1;
    for(i=0;i<time;i++)
        x*=10;
    return x;
}

int is_digit(char* str)
{
    int i,len=strlen(str);
    char c;
    for(i=0;i<len;i++)
    {
        c=*(str+i);
        if(!(c<='9'&&c>='0'))
            return -1;
    }
    return atoi(str);
}

