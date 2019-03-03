#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[]="hello",b[]="hello";
    int lena,lenb,i,x;
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++)
    {
        x=*(a+i)-*(b+i);
        if(x>0)
        {
            printf("string a > string b\n");
            return 0;
        }
        else if(x<0)
        {
            printf("string a < string b\n");
            return 0;
        }
    }
    printf("string a = string b\n");
    return 0;
}
