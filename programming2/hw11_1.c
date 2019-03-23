#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word_Frequently
{
    char word[20];
    int freq;
};
typedef struct word_Frequently word_Freq;

void str_done(char*,char*,char*);
void str_sort(char**,int);

int main(void)
{
    char article[200],w1[15],w2[15],c;
    //printf("program start\n");
    scanf("%[^\n]",article);
    c=getchar();
    scanf("%[^\n]",w1);
    c=getchar();
    scanf("%[^\n]",w2);
    c=getchar();
    str_done(article,w1,w2);
    return 0;
}

void str_done(char* article,char* w1,char* w2)
{
    char *a[20];
    int num=0,i;
    a[0]=strtok(article," ");
    while(a[num]!=NULL)
    {
        num++;
        a[num]=strtok(NULL," ");
    }
    w1=strtok(w1," ");
    w2=strtok(w2," ");
    for(i=0;i<num;i++)
    {
        if(strcmp(w1,a[i])==0)
            printf("%s ",w2);
        else
            printf("%s ",a[i]);
    }
    puts("");
    for(i=0;i<num;i++)
    {
        if(strcmp(w1,a[i])==0)
            printf("%s ",w2);
        printf("%s ",a[i]);
    }
    puts("");
    for(i=0;i<num;i++)
    {
        if(strcmp(w1,a[i])!=0)
            printf("%s ",a[i]);
    }
    puts("");
    str_sort(a,num);
    return;
}

void str_sort(char** a,int num)
{
    word_Freq w_f[num];
    char a_dif[num][20],format[]="no",ctemp[20];
    int i,j,appear[num],different=0,same,temp;
    for(i=0;i<num;i++) strcpy(a_dif[i],a[i]);
    for(i=0;i<num;i++)  //出現頻率計算
    {
        if(strcmp(a_dif[i],format)==0) continue;
        same=1;
        for(j=i+1;j<num;j++)
        {

            if(strcmp(a[i],a_dif[j])==0)
            {
                same++;
                strcpy(a_dif[j],format);
            }
        }
        w_f[different].freq=same;
        strcpy(w_f[different].word,a[i]);
        different++;
    }
    for(i=0;i<different;i++)    //先依照頻率排序
    {
        for(j=i+1;j<different;j++)
        {
            if(w_f[i].freq<w_f[j].freq)
            {
                temp=w_f[i].freq;
                w_f[i].freq=w_f[j].freq;
                w_f[j].freq=temp;
                strcpy(ctemp,w_f[i].word);
                strcpy(w_f[i].word,w_f[j].word);
                strcpy(w_f[j].word,ctemp);
            }
        }
    }
    for(i=0;i<different;i++)    //在依照辭典方法排序
    {
        for(j=i+1;j<different;j++)
        {
            if(w_f[i].freq!=w_f[j].freq) break;
            else
            {
                //比較小的往前挪
                if(strcmp(w_f[j].word,w_f[i].word)<0)
                {
                    temp=w_f[i].freq;
                    w_f[i].freq=w_f[j].freq;
                    w_f[j].freq=temp;
                    strcpy(ctemp,w_f[i].word);
                    strcpy(w_f[i].word,w_f[j].word);
                    strcpy(w_f[j].word,ctemp);
                }
            }
        }
    }
    for(i=0;i<different;i++)
        printf("%s %d\n",w_f[i].word,w_f[i].freq);
    return;
}


