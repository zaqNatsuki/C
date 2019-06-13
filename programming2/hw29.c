#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Company
{
    char name[11];      //Company Name
    char site[11];      //Company Position
    char topic[11];     //Company Topic
    char country[11];   //From which Country
    int award;          //get how much award
}company;

//1降序、2生序
int initial(company*);
void doSort(company*,char*,int,int);
void getCopy(company*,char[][15][11],int,char*);
void getSwitch(char*,char*);
void output(company*,char[][15][11],int);

int main(void)
{
    int i,j,num=0,dir;
    //if(d[j]>d[i])升序
    char detail[10];
    company com[15];
    num=initial(com);
    while(1)
    {
        scanf("%s",detail);
        if(strcmp("exit",detail)==0) break;
        scanf("%d",&dir);
        doSort(com,detail,num,dir);
    }
    return 0;
}

int initial(company* com)
{
    int i,t=0;
    char detail[11];
    while(1)
    {
        scanf("%s",detail);
        if(strcmp("-1",detail)==0) break;
        strcpy(com[t].name,detail);
        scanf("%s",com[t].site);
        scanf("%s",com[t].topic);
        scanf("%s",com[t].country);
        scanf("%d",&(com[t].award));
        t++;
    }
    return t;
}

void doSort(company *com,char *detail,int num,int dir)
{
    int i,j;
    char comCopy[2][15][11],temp[11];
    getCopy(com,comCopy,num,detail);
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(dir==1)      //降序
            {
                if(strcmp(comCopy[0][j],comCopy[0][i])<0)
                {
                    getSwitch(comCopy[0][j],comCopy[0][i]);
                    getSwitch(comCopy[1][j],comCopy[1][i]);
                }
                else if(strcmp(comCopy[0][j],comCopy[0][i])==0)
                {
                    if(strcmp(comCopy[1][j],comCopy[1][i])<0)
                    {
                        getSwitch(comCopy[1][j],comCopy[1][i]);
                        getSwitch(comCopy[0][j],comCopy[0][i]);
                    }
                }

            }
            else            //升序
            {
                if(strcmp(comCopy[0][i],comCopy[0][j])<0)
                {
                    getSwitch(comCopy[0][i],comCopy[0][j]);
                    getSwitch(comCopy[1][i],comCopy[1][j]);
                }
                else if(strcmp(comCopy[0][i],comCopy[0][j])==0)
                {
                    if(strcmp(comCopy[1][j],comCopy[1][i])>0)
                    {
                        getSwitch(comCopy[1][j],comCopy[1][i]);
                        getSwitch(comCopy[0][j],comCopy[0][i]);
                    }
                }
            }
        }
    }
    output(com,comCopy,num);
    return;
}

void getCopy(company *com,char comCopy[][15][11],int num,char *word)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(strcmp(word,"name")==0)
        {
            strcpy(comCopy[0][i],com[i].name);
        }
        else if(strcmp(word,"site")==0)
        {
            strcpy(comCopy[0][i],com[i].site);
        }
        else if(strcmp(word,"country")==0)
        {
            strcpy(comCopy[0][i],com[i].country);
        }
        else if(strcmp(word,"topic")==0)
        {
            strcpy(comCopy[0][i],com[i].topic);
        }
        else if(strcmp(word,"award")==0)
        {
            *(comCopy[0][i])=com[i].award+'0';
        }
        strcpy(comCopy[1][i],com[i].site);
    }
    return;
}

void getSwitch(char* s1,char* s2)
{
    char temp[11];
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
    return;
}

void output(company* com,char out[][15][11],int num)
{
    int i,j;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(strcmp(out[1][i],com[j].site)==0)
                printf("%s %s\n",com[j].name,com[j].site);
        }
    }
    return;
}

