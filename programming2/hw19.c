#include <stdio.h>
#include <stdlib.h>

struct activity_detial
{
    int id;
    int time[2];
};
typedef struct activity_detial activity;

void schedule(activity[],int,int);
int allow(int,int,int[]);

int main(void)
{
    int room,n,i;
    scanf("%d",&room);
    scanf("%d",&n);
    activity act[n];
    for(i=0;i<n;i++)
        scanf("%d %d %d",&act[i].id,&act[i].time[0],&act[i].time[1]);
    schedule(act,room,n);
    return 0;
}

void schedule(activity act[],int room,int n)
{
    int t=0,i,max=2,judge,combine=0,j,k,able=1,longest_time=0,most_use=0;
    int *re=NULL,hour[24];
    re=(int*)malloc(sizeof(int)*n);
    for(i=1;i<n;i++) max*=10;
    for(i=1;i<max;i++)
    {
        if((combine=allow(i,n,re))!=-1)
        {
            able=1;t=0;
            for(j=0;j<24;j++) hour[j]=0;
            for(j=0;j<combine;j++)
            {
                for(k=act[re[j]-1].time[0];k<act[re[j]-1].time[1];k++)
                {
                    if(++hour[k]>room)
                    {
                        able=0;
                        break;
                    }
                }
                if(able==0) break;
            }
            if(able)
            {
                for(j=0;j<24;j++) t+=hour[j];
                if(t>longest_time) longest_time=t;
                if(combine>most_use) most_use=combine;
            }
        }
    }
    printf("%d\n%d\n",longest_time,most_use);
    free(re);
    return;
}

int allow(int n,int big,int re[])
{
    int i=0,t=0,f;
    while(n>0)
    {
        f=n%10;
        if(f>big||f==0) return -1;
        for(i=0;i<t;i++)
            if(f==re[i]) return -1;
        re[t++]=f;
        n/=10;
    }
    return t;
}

