#include <stdio.h>
#include <string.h>

int getLen(char*);

int main(void)
{
    int len=0;
    char s[100];
    scanf("%s",s);
    len=getLen(s);
    printf("%d\n%d\n",len,strlen(s));
    return 0;
}

int getLen(char* s)
{
    if(*s=='\0')
        return 0;//如果return 1代表長度包括空字元
    else
        return getLen(s+1)+1;
}
