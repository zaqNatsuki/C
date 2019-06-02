#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct University
{
    char name[11];
    char feature[7][3];
    int feature_number;
}university;

void initial(university*,int);

int main(void)
{
    printf("hw30->Program start\n");
    int university_num,i=0,j,search_num;
    scanf("%d",&university_num);
    university *school=(university*)malloc(sizeof(university)*university_num);
    initial(school,university_num);
    scanf("%d",&search_num);
    /*for(i=0;i<n;i++)
    {
        printf("%s ",school[i].name);
        for(j=0;j<school[i].feature_number;j++)
        {
            printf("%s ",school[i].feature[j]);
        }
        printf("\n");
    }*/
    return 0;
}

void initial(university *school,int n)
{
    int i=0,j=0;
    char name[10],properties[20],*p=NULL;
    while(i<n)
    {
        //取得大學名稱
        scanf("%s",name);
        strcpy(school[i].name,name);
        //取得大學屬性
        scanf(" %[^\n]",properties);getchar();
        j=0;
        p=strtok(properties," ");
        while(p!=NULL)
        {
            strcpy(school[i].feature[j],p);
            p=strtok(NULL," ");
            j++;
        }
        school[i].feature_number=j;
        i++;
    }
    return;
}

