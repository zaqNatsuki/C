#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
    char name[50];
    int list[100];
    int byte;
};

int writeFile(int*,char*,struct file*);
int readFile(int,char*,struct file*);
int editFile(int,char*,struct file*);
void DecimalToBinary(int);

int main(void)
{
    int mode=0,n=0,error=0;
    char path[50]="";
    struct file fileDetail[10];
    while(1)
    {
        scanf("%d",&mode);
        if(mode==4) break;
        scanf(" %[^\n]",path);getchar();
        if(mode==1) error=writeFile(&n,path,fileDetail);
        else if(mode==2) error=readFile(n,path,fileDetail);
        else error=editFile(n,path,fileDetail);
        if(error==-1) printf("Error\n");
    }
    return 0;
}

void DecimalToBinary(int n)
{
    int i=0,binary[8];
    for(i=0;i<8;i++) binary[i]=0;
    i=0;
    while(n>0)
    {
        binary[i++]=n%2;
        n/=2;
    }
    for(i=7;i>=0;i--)
        printf("%d ",binary[i]);
    puts("");
    return;
}

int writeFile(int *n,char* path,struct file* fileDetail)
{
    int time=0,input=0,i;
    for(i=0;i<*n;i++)
    {
        if(strcmp(path,fileDetail[i].name)==0)
        {
            while(input!=-1)
            {
                scanf("%d",&input);
            }
            return -1;
        }
    }
    strcpy(fileDetail[*n].name,path);
    while(1)
    {
        scanf("%d",&input);
        if(input==-1) break;
        fileDetail[*n].list[time++]=input;
    }
    fileDetail[*n].byte=time;
    *n+=1;
    return 1;
}

int readFile(int n,char* path,struct file* fileDetail)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(strcmp(path,fileDetail[i].name)==0)
        {
            printf("%d bytes\n",fileDetail[i].byte);
            for(j=0;j<fileDetail[i].byte;j++)
            {
                DecimalToBinary(fileDetail[i].list[j]);
            }
            return 1;
        }
    }
    return -1;
}

int editFile(int n,char* path,struct file* fileDetail)
{
    int i,turn=0,change=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(path,fileDetail[i].name)==0)
        {
            scanf("%d",&turn);
            scanf("%d",&change);
            if(turn>fileDetail[i].byte) return -1;
            fileDetail[i].list[turn-1]=change;
            return 1;
        }
    }
    return -1;
}

