#include <stdio.h>
#include <string.h>
#include <ctype.h>

void frequent(char*);
void lower(char*);

int main(void)
{
    //printf("program start\n");
    char str[100];
    gets(str);
    puts("");
    frequent(str);
    return 0;
}

void frequent(char* str)
{
    int i,time=0,num_word=1;
    int appear[100];
    char *p,*word[100];
    for(i=0;i<100;i++) appear[i]=0;
    lower(str);
    p=strtok(str," ");
    word[0]=p;
    while(p!=NULL)
    {
        for(i=0;i<num_word;i++)
        {
            if(strcmp(p,word[i])==0)
            {
                appear[i]++;
                break;
            }
            else
                if(i==num_word-1)
                {
                    word[num_word]=p;
                    appear[num_word]++;
                    num_word++;
                    break;
                }
        }
        p=strtok(NULL," ");
        time++;
    }
    for(i=0;i<num_word;i++)
        printf("%s %d\n",word[i],appear[i]);
    return;
}

void lower(char* str)
{
    int len,i;
    char c;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        c=*(str+i);
        if('A'<=c&&c<='Z')
            *(str+i)+=32;
    }
    return;
}
