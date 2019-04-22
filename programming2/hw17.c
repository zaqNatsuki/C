#include <stdio.h>
#include <string.h>

struct Student
{
    char name;
    char wishList[10];
    char choose;
};
typedef struct Student student;

struct Teacher
{
    char name;
    char wishList[10];
    char choose;
};
typedef struct Teacher teacher;

int initial(student[],teacher[]);
void wishSort_stu(student[],teacher[],int);
int wishSort_tch(char,char,teacher,int);

int main(void)
{
    int num=0,i,j;
    student stu[10];
    teacher tch[10];
    num=initial(stu,tch);
    wishSort_stu(stu,tch,num);
    for(i=0;i<num;i++)
    {
        printf("%c->%c\n",stu[i].name,stu[i].choose);
    }
    /*for(i=0;i<num;i++)
    {
        printf("%c->",tch[i].name);
        for(j=0;j<num;j++)
        {
            printf("%c ",tch[i].wishList[j]);
        }
        printf("\n");
    }*/
    return 0;
}

int initial(student stu[],teacher tch[])
{
    int i,j,n=0;
    char temp='0';
    while(1)
    {
        scanf("%c",&temp);
        if(temp=='\n') break;
        else if(temp!=',' && temp!=' ')  stu[0].wishList[n++]=temp;
    }
    for(i=1;i<n;i++)
    {
        j=0;
        while(1)
        {
            scanf("%c",&temp);
            if(temp=='\n') break;
            else if(temp!=',' && temp!=' ')  stu[i].wishList[j++]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        j=0;
        while(1)
        {
            scanf("%c",&temp);
            if(temp=='\n') break;
            else if(temp!=',' && temp!=' ')  tch[i].wishList[j++]=temp;
        }
        stu[i].name='Z'-n+1+i;
        tch[i].name='A'+i;
        stu[i].choose=tch[i].choose='0';
    }
    return n;
}

void wishSort_stu(student stu[],teacher tch[],int num)
{
    int i,now=0,success,j;
    for(now=0;now<num;now++)
    {
        for(i=0;i<num;i++)
        {
            if(stu[i].choose!='0') continue;
            if(tch[stu[i].wishList[now]-'A'].choose!='0') continue;
            success=1;
            for(j=i;j<num;j++)
            {
                if(stu[j].choose!='0') continue;
                if(stu[i].wishList[now]==stu[j].wishList[now] && i!=j)
                {
                    if(wishSort_tch(stu[i].name,stu[j].name,tch[stu[i].wishList[now]-'A'],num)==2)
                    {
                        success=0;
                        break;
                    }
                }
            }
            if(success)
            {
                stu[i].choose=stu[i].wishList[now];
                tch[stu[i].wishList[now]-'A'].choose=stu[i].name;
            }
        }
    }
    return;
}

int wishSort_tch(char stu1,char stu2,teacher tch,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(tch.wishList[i]==stu1) return 1;
        else if(tch.wishList[i]==stu2) return 2;
    }
}


