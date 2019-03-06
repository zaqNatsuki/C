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
    int ranking;
    int pass;
    int skip;
    float average;
    _course cou[10];
};
typedef struct student _student;

void compute(int,_student []);
void out(int,_student []);

int main(void)
{
    int n,i,j;
    scanf("%d",&n);
    _student stu[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %s",&stu[i].id,stu[i].stu_Name);
        scanf("%d",&stu[i].lesson);
        stu[i].pass=stu[i].skip=0;
        for(j=0;j<stu[i].lesson;j++)
        {
            scanf("%s %d %d",stu[i].cou[j].class_Name,
                  &stu[i].cou[j].class_Score,&stu[i].cou[j].final_Score);
        }
    }
    compute(n,stu);
    return 0;
}

void compute(int n,_student stu[])
{
    int i,j,k,total,time,rank=0;
    float temp[n+1];
    for(i=0;i<n;i++)
    {
        temp[0]=total=time=0;
        for(j=0;j<stu[i].lesson;j++)
            {
                if(stu[i].cou[j].final_Score>=60)
                {
                    stu[i].pass+=stu[i].cou[j].class_Score;
                }
                total+=stu[i].cou[j].final_Score*stu[i].cou[j].class_Score;
                time+=stu[i].cou[j].class_Score;
            }
            stu[i].average=(float)total/time;
    }
    for(i=100;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(stu[j].average>=i&&stu[j].skip==0)
            {
                rank++;
                stu[j].ranking=rank;
                stu[j].skip=1;
            }
        }
    }
    out(n,stu);
    return;
}

void out(int n,_student stu[])
{
    int id=1,i,j;
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
                printf("%d\n%.2f\n%d\n",stu[i].pass,stu[i].average,stu[i].ranking);
                break;
            }
            if(i==n-1) printf("ERROR\n");
        }
    }
    return;
}
