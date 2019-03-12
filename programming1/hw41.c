#include <stdio.h>

int check_Base_Number(int,int);         //檢查輸入
void convert_to_newbase(int,int);       //進位轉換

int main(void)
{
    int newBase=0,number=0,check=0;
    //printf("Program Start\n");
    scanf("%d %d",&newBase,&number);
    check=check_Base_Number(newBase,number);
    if(check==1)
    {
        convert_to_newbase(newBase,number);
    }
    else
    {
        printf("E\n");
    }
    return 0;
}

int check_Base_Number(int base,int num)
{
    if(base>=2 && base<=16)
    {
        if(num>=0 && num<=1000000000)
            return 1;
    }
    return 0;
}

void convert_to_newbase(int newBase,int num)
{
    char big[6]={'A','B','C','D','E','F'};
    char out[30];
    char trans,time=0,i;
    while(num>0)
    {
        trans=num%newBase;
        if(trans>=10)
        {
            out[time]=big[trans-10];
        }
        else
        {
            out[time]=trans+'0';
        }
        num=num/newBase;
        time+=1;
    }
    for(i=time-1;i>=0;i--)
    {
        printf("%c",out[i]);
    }
    printf("\n");
    return;
}

