#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct University
{
    char name[11];
    int feature[7];
}university;

void initial(university*,int);
int translate(char*);
int amount(char*,char);
void dictionary_Sort(char[][11],int);
void Myselect(university*,int);
void check(university*,char[][11],int*,int);

int main(void)
{
    //printf("hw30->Program start\n");
    int university_num,i=0,j,search_num;
    char s[5];
    scanf("%d",&university_num);
    university *school=(university*)malloc(sizeof(university)*university_num);
    initial(school,university_num);
    scanf("%d",&search_num);scanf("%[\n]",s);//getchar();
    for(i=0;i<search_num;i++)
    {
        Myselect(school,university_num);
    }
    free(school);
    return 0;
}

void initial(university *school,int n)
{
    int i=0,j=0,x;
    char name[10],properties[20],*p=NULL;
    while(i<n)
    {
        for(j=0;j<7;j++) school[i].feature[j]=0;
        //取得大學名稱
        scanf("%s",name);
        strcpy(school[i].name,name);
        //取得大學屬性
        scanf(" %[^\n]",properties);getchar();
        j=0;
        p=strtok(properties," ");
        while(p!=NULL)
        {
            //strcpy(school[i].feature[j],p);
            x=translate(p);
            school[i].feature[x]+=1;
            p=strtok(NULL," ");
            j++;
        }
        i++;
    }
    return;
}

int translate(char *feature)
{
    if(strcmp(feature,"BC")==0) return 0;
    else if(strcmp(feature,"NC")==0) return 1;
    else if(strcmp(feature,"CT")==0) return 2;
    else if(strcmp(feature,"NS")==0) return 3;
    else if(strcmp(feature,"NM")==0) return 4;
    else if(strcmp(feature,"HL")==0) return 5;
    else if(strcmp(feature,"NL")==0) return 6;
}

void dictionary_Sort(char fit[][11],int n)
{
    int i,j,temp=0,k;
    char name[11];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(strcmp(fit[i],"empty")==0 || strcmp(fit[j],"empty")==0) continue;
            if(strcmp(fit[j],fit[i])>0)
            {
                strcpy(name,fit[j]);
                strcpy(fit[j],fit[i]);
                strcpy(fit[i],name);
            }
        }
    }
    return;
}

int amount(char *s,char key)
{
    int i,t=0,len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(*(s+i)==key) t++;
    }
    return t;
}

void Myselect(university *school,int num)
{
    int i=0,j,cmp[7],t;
    char feature[3],fit[7][11],c;
    for(j=0;j<7;j++)
    {
        cmp[j]=0;
        strcpy(fit[j],"empty");
    }
    while(1)
    {
        c=getchar();
        if(c==' ') continue;
        else if(c=='+')
        {
            check(school,fit,cmp,num);
            for(j=0;j<7;j++)
                cmp[j]=0;
        }
        else if(c=='\n')
        {
            check(school,fit,cmp,num);
            break;
        }
        else
        {
            feature[0]=c;
            c=getchar();
            feature[1]=c;
            t=translate(feature);
            cmp[t]=1;
        }
    }
    dictionary_Sort(fit,num);
    for(i=0;i<num;i++)
        if(strcmp("empty",fit[i])!=0) printf("%s ",fit[i]);
    printf("\n");
    return;
}

void check(university* school,char fit[][11],int *cmp,int num)
{
    int i,j,isOK;
    for(i=0;i<num;i++)
    {
        isOK=1;
        for(j=0;j<7;j++)
        {
            if(school[i].feature[j]==0 && cmp[j]==1)
            {
                isOK=0;
                break;
            }
        }
        if(isOK)
        {
            for(j=0;j<7;j++)
            {
                if(strcmp(fit[j],school[i].name)==0) break;
                if(strcmp(fit[j],"empty")==0)
                {
                    strcpy(fit[j],school[i].name);
                    break;
                }
            }
        }
    }
    return;
}


