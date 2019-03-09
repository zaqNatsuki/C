#include <stdio.h>
#include <string.h>

int str_del(int,char*,int,char*,int);
void sub_string(char*,char*);
int str_compare(char*,char*);
void str_sort(int,char [][100]);
void str_copy(char*,char*);


int main(void)
{

    int i,num=1;
    char c,word[100][100];
    //printf("program start\n");
    scanf("%s",word[0]);
    while(1)
    {
        scanf("%[^\n]",word[num]);
        c=getchar();
        if(strcmp("-1",word[num])==0) break;
        num++;
    }
    for(i=1;i<num;i++)sub_string(word[i],word[0]);
    str_sort(num,word);
    return 0;
}

int str_del(int position,char *word,int word_len,char *del,int del_len)
{
    int i,len=0;
    for(i=position;i<word_len;i++)
    {
        if(i+del_len>=word_len)
            *(word+i)='\0';
        *(word+i)=*(word+i+del_len);
    }
    len=strlen(word);
    return len;
}

void sub_string(char* word,char* del)
{
    int i,len=0,same=0,del_len=0;
    del_len=strlen(del);
    len=strlen(word);
    for(i=0;i<len;i++)
    {
        if(*(word+i)==*(del+same)) same++;
        else same=0;
        if(same==del_len)
        {
            i=i-del_len+1;
            len=str_del(i,word,len,del,del_len);
        }
    }
    return;
}

int str_compare(char* w1,char* w2)
{
    int i,w1_len,w2_len,len,re;
    w1_len=strlen(w1);
    w2_len=strlen(w2);
    len=w1_len>=w2_len?w1_len:w2_len;
    for(i=0;i<len;i++)
    {
        if(*(w1+i)-*(w2+i)>0) return 1;
        else if(*(w1+i)-*(w2+i)<0) return -1;
    }
    if(w1_len==w2_len) return 0;
    re=w1_len>w2_len?1:-1;
    return re;
}

void str_sort(int num,char word[][100])
{
    int i,j,compare=0;
    char temp[100];
    str_copy(temp,word[1]);
    for(i=1;i<num;i++)
    {
        for(j=1;j<num;j++)
        {
            //如果寫成 str_compare(word[i],word[j])==1,結果會變成最大的在最前面
            if(str_compare(word[j],word[i])==1)
            {
                str_copy(temp,word[i]);
                str_copy(word[i],word[j]);
                str_copy(word[j],temp);
            }
        }
    }
    for(i=1;i<num;i++) printf("%s\n",word[i]);
    return;
}

void str_copy(char* _get,char* _give)
{
    int give_len,i,get_len;
    give_len=strlen(_give);
    for(i=0;i<give_len+1;i++) *(_get+i)='\0';
    for(i=0;i<give_len;i++) *(_get+i)=*(_give+i);
    return;
}

