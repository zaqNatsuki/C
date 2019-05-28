#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Stack為先進後出
typedef struct Homework
{
    char name[10];
    int isDelay;
    struct Homework *next;
}HW;

void work(HW*);
void push(HW*,char*,int);
void pop(HW*);
void rest(HW*);

int main(void)
{
    HW *top=(HW*)malloc(sizeof(HW));
    top->next=NULL;
    work(top);
    free(top);
    return 0;
}

void work(HW *top)
{
    int command=0;
    char input[10];
    while(1)
    {
        scanf("%[^\n]",input);getchar();
        if(strcmp(input,"-1")==0) break;
        push(top,input,0);
    }
    while(1)
    {
        scanf("%d",&command);
        if(command==1)
        {
            scanf("%s",input);getchar();
            push(top,input,1);
        }
        else if(command==2) pop(top);
        else
        {
            rest(top);
            break;
        }
    }
    return;
}

void push(HW *top,char *name,int late)
{
    HW *homework=(HW*)malloc(sizeof(HW));
    strcpy(homework->name,name);
    if(late==1) homework->isDelay=1;
    else homework->isDelay=0;
    homework->next=top->next;
    top->next=homework;
    return;
}

void pop(HW* top)
{
    HW *hw;
    if(top->next!=NULL)
    {
        hw=top->next;
        if(hw->isDelay==1)
            printf("%s's HW is delay\n",hw->name);
        else
            printf("%s's HW is not delay\n",hw->name);
        if(hw->next!=NULL) top->next=hw->next;
        else top->next=NULL;
        free(hw);
    }
    else
        printf("Empty\n");
    return;
}

void rest(HW* top)
{
    if(top->next==NULL) printf("Empty\n");
    else
    {
        while(top->next!=NULL)
            pop(top);
    }
}

