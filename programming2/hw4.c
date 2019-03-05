#include <stdio.h>
#include <math.h>

struct Student
{
    int id;
    char name[10];
    int score1;
    int score2;
    int score3;
    int total;
    int ranking;
}stu[];
typedef struct Student s_stu;

void out(s_stu);
void getRank(int,s_stu []);
void compute(int,int [],s_stu []);
void f(float*);

int main(void)
{
    int n=0,i;
    //printf("program start\n");
    scanf("%d",&n);
    s_stu stu[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %s %d %d %d",&stu[i].id,stu[i].name,&stu[i].score1,
              &stu[i].score2,&stu[i].score3);
    }
    getRank(n,stu);
    return 0;
}

void getRank(int n,s_stu stu[])
{
    int i,j,k,temp[n+1];
    temp[0]=temp[1]=0;
    for(i=0;i<n;i++)
    {
        stu[i].total=stu[i].score1+stu[i].score2+stu[i].score3;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(stu[i].total>temp[j])
            {
                for(k=i;k>=j;k--)
                    temp[k+1]=temp[k];
                temp[j]=stu[i].total;
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(stu[j].total==temp[i])
            {
                stu[j].ranking=i+1;
                out(stu[j]);
            }
    }
    compute(n,temp,stu);
    return;
}

void out(s_stu stu)
{
    printf("%d %s %d %d %d %d %d\n",stu.id,stu.name,stu.score1,
           stu.score2,stu.score3,stu.total,stu.ranking);
}

void compute(int n,int temp[],s_stu stu[])
{
    int i;
    float s1,s2,s3,t1,tmid,variance,sd,tb,ts;
    s1=s2=s3=t1=tmid=sd,variance=tb=ts=0.0;
    if(n%2==1) tmid=temp[n/2];
    //整數/整數的結果還是整數，因此要先將其中一個轉成float
    else tmid=(temp[n/2]+temp[n/2-1])/2.0;
    for(i=0;i<n;i++)
    {
        s1+=stu[i].score1;
        s2+=stu[i].score2;
        s3+=stu[i].score3;
        t1+=stu[i].total;
        //printf("%d ",temp[i]);
    }
    t1/=n;
    for(i=0;i<n;i++)
    {
        variance+=pow(stu[i].total-t1,2);
        if(stu[i].total>tmid) tb+=stu[i].total;
        else if(stu[i].total<tmid) ts+=stu[i].total;
    }
    s1/=n;
    s2/=n;
    s3/=n;
    tb=tb/(n/2);
    ts=ts/(n/2);
    variance/=n;
    sd=sqrt(variance);
    f(&s1);
    f(&s2);
    f(&s3);
    f(&t1);
    f(&tmid);
    f(&variance);
    f(&sd);
    f(&tb);
    f(&ts);
    printf("%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",
           s1,s2,s3,t1,tmid,variance,sd,tb,ts);
    return;
}

void f(float* n)
{
    float x;
    x=(int)(*n*100+0.5);
    *n=x/100;
    return;
}

