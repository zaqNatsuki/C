#include <stdio.h>
#include <stdlib.h>

void add(int,int,int*,int*);
void different(int,int,int*,int*);

int main(void)
{
    char c1[60],c2[60];
    int n1[60],n2[60];
    int len1=0,len2=0,i,t1=60,t2=60;
    for(i=0;i<60;i++)
    {
        //初始化內容為空字元'\0',方便後面取得長度
        c1[i]=c2[i]=n1[i]=n2[i]='\0';
    }
    //printf("program start\n");
    scanf("%s",c1);
    scanf("%s",c2);
    for(i=59;i>=0;i--)      //大數長度取得
    {
        if(c1[i]!='\0')
        {
            t1--;
            n1[t1]=c1[i]-'0';
            len1++;
        }
        if(c2[i]!='\0')
        {
            t2--;
            n2[t2]=c2[i]-'0';
            len2++;
        }
    }
    add(len1,len2,n1,n2);
    different(len1,len2,n1,n2);
    return 0;
}

void add(int len1,int len2,int* n1,int* n2)
{
    int i,ans[60],carry=0;
    for(i=0;i<60;i++)
        ans[i]=10;
    for(i=59;i>=0;i--)
    {
        if(i<60-len1&&i>=60-len2)       //代表n1陣列裡的數字都運算過了
            ans[i]=n2[i]+carry;
        else if(i<60-len2&&i>=60-len1)  //代表n2陣列裡的數字都運算過了
            ans[i]=n1[i]+carry;
        else if(i>=60-len1&&i>=60-len2) //代表兩個陣列都尚未運算結束
            ans[i]=n1[i]+n2[i]+carry;
        else
            break;
        carry=ans[i]/10;
        ans[i]%=10;
    }
    for(i=0;i<60;i++)
        if(ans[i]!=10)
            printf("%d",ans[i]);
    printf("\n");
    return;
}

void different(int len1,int len2,int* n1,int* n2)
{
    int i,ans[60],borrow=0,s=0;
    for(i=0;i<60;i++)
        ans[i]=0;
    if(len1>len2)s=1;
    else if(len1<len2)s=2;
    else
        for(i=0;i<60;i++)
        {
            if(n1[i]>n2[i])
            {
                s=1;
                break;
            }
            else if(n1[i]<n2[i])
            {
                s=2;
                break;
            }
        }
    if(s==0)            //代表n1=n2，直接=0
    {
        printf("0\n");
        return;
    }
    for(i=59;i>=0;i--)
    {
        if(s==1)        //代表n1>n2
            ans[i]=n1[i]-n2[i]-borrow;
        else if(s==2)   //代表n2>n1
            ans[i]=n2[i]-n1[i]-borrow;
        if(ans[i]<0)
        {
            borrow=1;
            ans[i]+=10;
        }
        else
            borrow=0;
    }
    if(s==2)printf("-");
    for(i=0;i<60;i++)
        printf("%d",ans[i]);
    return;
}

