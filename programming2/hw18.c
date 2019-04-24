#include <stdio.h>
#include <string.h>

void doThing(int,char*);
int binary_to_Decimal(const char*,int);
int loopCircuit(int);
void decimal_to_binary(int,int,char*);//n,len,binary
void print(int,char*);

int main(void)
{
    int len=0,i,act=0;
    char binary[11],temp,c;
    while(1)
    {
        scanf("%c",&temp);
        if(temp=='\n')
        {
            doThing(len,binary);
            len=0;
            for(i=0;i<11;i++) binary[i]='0';
            scanf("%d",&act);
            c=getchar();
            if(act==-1) break;
        }
        else if(temp=='0'||temp=='1') binary[len++]=temp;
    }
    return 0;
}

void doThing(int len,char* binary)
{
    int n=0,totalLoop=0;
    n=binary_to_Decimal(binary,len);
    totalLoop=loopCircuit(n);
    decimal_to_binary(totalLoop,11,binary);
    print(11,binary);
    return;
}

int binary_to_Decimal(const char* binary,int binary_len)
{
    int i,multi=1,ten=0;
    for(i=binary_len-1;i>=0;i--)
    {
        ten+=(binary[i]-'0')*multi;
        multi*=2;
    }
    return ten;
}

int loopCircuit(int n)
{
    int i,t=0,x=n;
    if(n==1 || n==0) return 0;
    else
    {
        while(x>1)
        {
            if(x%2==0) x/=2;
            else x=(x+1)/2;
            t++;
        }
        return t+loopCircuit(n-1);
    }
}

void decimal_to_binary(int loop,int len,char* binary)
{
    int i,t=0;
    while(t<len)
    {
        binary[t++]=loop%2+'0';
        loop/=2;
    }
    return;
}

void print(int len,char* binary)
{
    int i;
    for(i=len-1;i>=0;i--)
        printf("%c",binary[i]);
    printf("\n");
    return;
}

