#include <stdio.h>
#include <string.h>

void str_subcmp(char*,char*,char*);
void str_PartCopy(char*,char*,int,int);

int main(void)
{
    char a[100],b[100],same_str[100]="\0";
    //printf("program start\n");
    scanf("%s",a);
    scanf("%s",b);
    str_subcmp(a,b,same_str);
    printf("%s\n",same_str);
    return 0;
}

void str_subcmp(char *a,char *b,char *same_str)
{
    int i,j,position=0;
    int a_len,b_len,same_len=0;
    a_len=strlen(a);
    b_len=strlen(b);
    for(i=0;i<a_len;i++)
    {
        same_len=position=j=0;
        while(j<b_len)
        {
            if(*(a+i+same_len)==*(b+j+same_len)) same_len++;
            else
            {
                same_len=0;
                j++;
            }
            if(same_len>strlen(same_str)) str_PartCopy(same_str,b,j,same_len);
        }
    }
    return;
}

void str_PartCopy(char *_get,char *_give,int first,int len)
{
    int i,position=0;
    for(i=first;i<first+len;i++,position++)
    {
        *(_get+position)=*(_give+i);
    }
    return;
}
