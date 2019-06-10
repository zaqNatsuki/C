#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s
{
    int data;
    struct node_s *left;
    struct node_s *right;
}node_t;

node_t* createNode(int);
void insert_Node(node_t*,int);
void output(node_t*);
void freeAll(node_t*);

int main(void)
{
    //printf("hw32_binary tree\n");
    int data,z=0;
    char c;
    node_t *head=NULL;
    while(1)
    {
        c=getchar();
        if(c=='p')
        {
            output(head);
            puts("");
        }
        else if(c=='i')
        {
            scanf("%d",&data);
            if(z==0)
            {
                z=1;
                head=createNode(data);
                continue;
            }
            insert_Node(head,data);
        }
        else if(c=='e') break;
    }
    freeAll(head);
    return 0;
}

node_t* createNode(int data)
{
    node_t *newNode=(node_t*)malloc(sizeof(node_t));
    newNode->left=newNode->right=NULL;
    newNode->data=data;
    return newNode;
}

void insert_Node(node_t *head,int data)
{
    node_t *newNode=NULL,*cur=head,*pre;
    newNode=createNode(data);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    while(1)
    {
        if(data<=cur->data)
        {
            if(cur->left==NULL)
            {
                cur->left=newNode;
                break;
            }
            else
                cur=cur->left;
        }
        else
        {
            if(cur->right==NULL)
            {
                cur->right=newNode;
                break;
            }
            else
                cur=cur->right;
        }
    }
    return;
}

void output(node_t* current)
{
    if(current==NULL)
    {
        printf("null\n");
        return;
    }
    if(current->left!=NULL) output(current->left);
    printf("%d ",current->data);
    if(current->right!=NULL) output(current->right);
    return;
}

void freeAll(node_t* current)
{
    if(current->left!=NULL) freeAll(current->left);
    if(current->right!=NULL) freeAll(current->right);
    //printf("%d ",current->data);
    free(current);
    return;
}

