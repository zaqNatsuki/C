#include <stdio.h>

int main(void)
{
    char a[]="android",b[]="oid";
    int lena,lenb,i,same=0;
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++)
    {
        if(*(a+i)==*(b+same)) same++;
        else same=0;
        if(same==lenb)
        {
            printf("True\n");
            return 0;
        }
    }
    printf("False\n");
    return 0;
}
