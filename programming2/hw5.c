#include <stdio.h>

struct course
{
    char class_Name[20];
    int class_Score;
    int final_Score;
};
typedef struct course _course;

struct student
{
    int id;
    char stu_Name[10];
    int lesson;
    _course cou[10];
};
typedef struct student _student;

int main(void)
{
    int n,i,j,id=1;
    scanf("%d",&n);
    _student stu[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %s",&stu[i].id,stu[i].stu_Name);
        scanf("%d",&stu[i].lesson);
        for(j=0;j<stu[i].lesson;j++)
        {
            scanf("%s %d %d",stu[i].cou[j].class_Name,
                  &stu[i].cou[j].class_Score,&stu[i].cou[j].final_Score);
        }
    }
    while(1)
    {
        scanf("%d",&id);
        if(id==0) break;
        for(i=0;i<n;i++)
        {
            if(id==stu[i].id)
            {
                printf("%d %s\n",id,stu[i].stu_Name);
                for(j=0;j<stu[i].lesson;j++)
                {
                    printf("%s %d %d\n",stu[i].cou[j].class_Name,
                           stu[i].cou[j].class_Score,stu[i].cou[j].final_Score);
                }
                break;
            }
            if(i==n-1) printf("ERROR\n");
        }
    }
    return 0;
}
