#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct MYQUEUE
{
    char name[10];
    struct MYQUEUE *nextQueue;
    struct MYQUEUE *nextHead;
    int data;   //第一個的data=整個Queue的長度
}myQueue;

void design_Queue(myQueue*);
void enQueue(myQueue*,int);
void createQueue(myQueue*,char*);
void notExistPrint(char*);
void deQueue(myQueue*);
void MergeQueue(myQueue*,myQueue*);
void printAll(myQueue*);
myQueue* findQueue(myQueue*,char*);
void freeAll(myQueue*);

int main(void)
{
    myQueue *initial;
    initial=(myQueue*)malloc(sizeof(myQueue));
    initial->nextHead=initial->nextQueue=NULL;
    design_Queue(initial);
    freeAll(initial);
    return 0;
}

void design_Queue(myQueue *initial)
{
    int cmd=0,data=0;
    char name[10];
    myQueue *temp1,*temp2;
    while(1)
    {
        scanf("%d",&cmd);
        if(cmd==1)          //create
        {
            scanf("%s",name);getchar();
            createQueue(initial,name);
        }
        else if(cmd==2)     //join
        {
            scanf("%s",name);scanf("%d",&data);
            temp1=findQueue(initial,name);
            if(temp1==NULL) notExistPrint(name);
            else enQueue(temp1,data);
        }
        else if(cmd==3)     //delete
        {
            scanf("%s",name);getchar();
            temp1=findQueue(initial,name);
            if(temp1==NULL) notExistPrint(name);
            else deQueue(temp1);
        }
        else if(cmd==4)     //merge
        {
            //char name1[10];
            scanf("%s",name);getchar();
            temp1=findQueue(initial,name);
            if(temp1==NULL) notExistPrint(name);
            scanf("%s",name);getchar();
            temp2=findQueue(initial,name);
            if(temp2==NULL) notExistPrint(name);
            if(temp1!=NULL && temp2 !=NULL) MergeQueue(temp1,temp2);
        }
        else if(cmd==5)     //printAll
        {
            printf("****************************************\n");
            printAll(initial);
            printf("****************************************\n");
        }
        else if(cmd==6) break;
    }
    return;
}

void createQueue(myQueue *initial,char *name)
{
    myQueue *now=initial,*mq;
    while(now->nextHead!=NULL)
    {
        now=now->nextHead;
    }
    mq=(myQueue*)malloc(sizeof(myQueue));
    now->nextHead=mq;
    mq->nextHead=mq->nextQueue=NULL;
    strcpy(mq->name,name);
    mq->data=0;
    return;
}

myQueue* findQueue(myQueue *initial,char *name)     //回傳前一個
{
    static myQueue *head;
    head=initial;
    myQueue *now=initial;
    while(head->nextHead!=NULL)
    {
        if(strcmp(now->name,name)==0)
            return head;
        head=now;
        now=now->nextHead;
    }
    return NULL;
}

void notExistPrint(char *name)
{
    printf("Queue %s isn't exist\n",name);
    return;
}

void enQueue(myQueue *head,int data)
{
    myQueue *temp,*constant_temp,*mq=(myQueue*)malloc(sizeof(myQueue));
    constant_temp=temp=head->nextHead;
    while(temp->nextQueue!=NULL)
    {
        temp=temp->nextQueue;
    }
    temp->nextQueue=mq;
    mq->nextQueue=NULL;
    mq->data=data;
    constant_temp->data+=1;
    return;
}

void deQueue(myQueue *head)
{
    myQueue *temp=head->nextHead,*release;
    release=temp->nextQueue;
    if(release==NULL) printf("Queue is empty\n");
    else
    {
        temp->nextQueue=release->nextQueue;
        temp->data-=1;
        free(release);
    }
    return;
}

void MergeQueue(myQueue *ma,myQueue *mb)
{
    myQueue *const_t1=ma->nextHead,*t1=ma->nextHead,*t2=mb->nextHead;
    mb->nextHead=t2->nextHead;
    while(t1->nextQueue!=NULL)
    {
        t1=t1->nextQueue;
    }
    t1->nextQueue=t2->nextQueue;
    const_t1->data+=t2->data;
    free(t2);
    return;
}

void printAll(myQueue *initial)
{
    myQueue *nowHead=initial,*nowQueue;
    if(initial->nextHead==NULL) printf("Isn't have any queue\n");
    while(nowHead->nextHead!=NULL)
    {
        nowHead=nowHead->nextHead;
        nowQueue=nowHead;
        printf("Queue Name:%s Queue Size:%d Queue Element:",nowHead->name,nowHead->data);
        if(nowHead->data==0)
        {
            printf("Queue is empty\n");
            continue;
        }
        while(nowQueue->nextQueue!=NULL)
        {
            nowQueue=nowQueue->nextQueue;
            printf("%d ",nowQueue->data);
        }
        printf("\n");
    }
    return;
}

void freeAll(myQueue *initial)
{
    myQueue *head=initial,*subQueue,*freeQueue,*freeHead=initial;
    while(freeHead->nextHead!=NULL)
    {
        freeHead=head;
        freeQueue=subQueue=head=head->nextHead;
        if(head==NULL) break;
        //printf("Queue->%s:",freeQueue->name);
        while(freeQueue->nextQueue!=NULL)
        {
            freeQueue=subQueue;
            subQueue=subQueue->nextQueue;
            if(freeQueue!=head)
            {
                //printf("%d ",freeQueue->data);
                free(freeQueue);
            }
        }
        //printf("free->%s\n",head->name);
        free(freeHead);
    }
    free(initial);
    return;
}

