#include <stdio.h>
#include <string.h>

void str_replace(char*,char*,char*);
int str_delete(char*,char*);
void str_insert(char*,int,char*);
int str_findSubstr(char*,char*);
void str_done(char*,char*,char*);

int main(void)
{
    char article[200],w1[20],w2[20],c,newArticle[200];
    int len,i;
    scanf("%[^\n]",article);
    c=getchar();
    scanf("%[^\n]",w1);
    c=getchar();
    scanf("%[^\n]",w2);
    c=getchar();
    len=strlen(article);
    str_done(article,w1,w2);
    return 0;
}

void str_done(char* article,char* w1,char* w2)
{
    int i,j,n,len=strlen(article)+1,x=0;
    char newArticle[len];
    for(j=0;j<3;j++)
    {
        for(i=0;i<len;i++) newArticle[i]=article[i];
        if(j==0) str_replace(newArticle,w1,w2);
        while(j==2 || j==1)
        {
            char newArticle1[len];
            for(i=0;i<len;i++) newArticle1[i]=article[i];
            //insert沒寫好其他兩個都寫好
            if(j==1)
            {
                n=str_delete(newArticle1,w1);
                if(n==-1) break;
                //str_insert(,n,w2);
            }
            else if(j==2)
            {
                n=str_delete(newArticle,w1);
                if(n==-1) break;
            }
        }
        printf("%s\n",newArticle);

    }
    return;
}

void str_replace(char* newArticle,char* w1,char* w2)
{
    int i,position;
    while(1)
    {
        position=str_delete(newArticle,w1);
        if(position==-1) break;
        str_insert(newArticle,position,w2);
    }
    return;
}

int str_delete(char* newArticle,char* w1)
{
    int len=strlen(newArticle)+1;
    int i,w1_len,position=0;
    w1_len=strlen(w1);
    position=str_findSubstr(newArticle,w1);
    if(position==-1) return position;
    for(i=position;i<len;i++)
    {
        *(newArticle+i)=*(newArticle+i+w1_len+1);
    }
    return position;
}

int str_findSubstr(char* article,char* w1)
{
    int i,len,len_w1,same=0,start=0;
    len=strlen(article);
    len_w1=strlen(w1);
    for(i=0;i<len;i++)
    {
        if(*(article+i)==*(w1+same)&&start==1) same++;
        else same=start=0;
        if(*(article+i)==' ') start=1;
        if(same==len_w1)
            return i-len_w1+1;
    }
    return -1;
}

void str_insert(char* article,int position,char* w2)
{
    int i,j,w2_len,len;
    w2_len=strlen(w2);
    len=strlen(article);
    for(i=len;i>=position;i--)
        *(article+i+w2_len+1)=*(article+i);
    for(i=position,j=0;i<position+w2_len;i++,j++)
        *(article+i)=*(w2+j);
    *(article+position+w2_len)=' ';
    return;
}


