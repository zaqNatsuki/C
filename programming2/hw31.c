#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct binary_s
{
    char data;
    int loc;
    struct binary_s* left;
    struct binary_s* right;
}binary_t;

void InPostOrder(binary_t*,char*,char*);
void PreInOrder(binary_t*,char*,char*);
void insertTree(binary_t*,int,char);
void createBinaryTree(char,char*,char,char*);
void freeAll(binary_t*);

int main(void)
{
    char c1,c2,s1[20],s2[20];
    scanf("%c",&c1);getchar();scanf("%s",s1);getchar();
    scanf("%c",&c2);getchar();scanf("%s",s2);getchar();
    createBinaryTree(c1,s1,c2,s2);
    return 0;
}

void createBinaryTree(char c1,char *s1,char c2,char *s2)
{
    binary_t *binary_tree=(binary_t*)malloc(sizeof(binary_t));
    if(c1=='I')
    {
        if(c2=='P') PreInOrder(binary_tree,s2,s1);
        else if(c2=='O') InPostOrder(binary_tree,s2,s1);
    }
    else
    {
        if(c1=='P') PreInOrder(binary_tree,s1,s2);
        else if(c1=='O') InPostOrder(binary_tree,s1,s2);
    }
    freeAll(binary_tree);printf("\n");
    return;
}

void PreInOrder(binary_t *binary_tree,char *preOrder,char *inOrder)
{
    int preLen=strlen(preOrder),inLen=strlen(inOrder),i,temp,j;
    binary_tree->data=*(preOrder);
    binary_tree->left=binary_tree->right=NULL;
    for(i=0;i<preLen;i++)
    {
        for(j=0;j<inLen;j++)
        {
            if(*(preOrder+i)=='-') break;
            if(*(inOrder+j)==*(preOrder+i))
            {
                if(i!=0)
                {
                    insertTree(binary_tree,j,*(preOrder+i));
                }
                else binary_tree->loc=j;
                *(preOrder+i)=*(inOrder+j)='-';
            }
        }
    }
}

void InPostOrder(binary_t *binary_tree,char *postOrder,char *inOrder)
{
    int postLen=strlen(postOrder),inLen=strlen(inOrder),i,temp,j;
    binary_tree->data=*(postOrder+postLen-1);
    binary_tree->left=binary_tree->right=NULL;
    for(i=postLen-1;i>=0;i--)
    {
        for(j=0;j<inLen;j++)
        {
            if(*(postOrder+i)=='-') break;
            if(*(inOrder+j)==*(postOrder+i))
            {
                if(i!=postLen-1)
                {
                    insertTree(binary_tree,j,*(postOrder+i));
                }
                else binary_tree->loc=j;
                *(postOrder+i)=*(inOrder+j)='-';
            }
        }
    }
    return;
}

void freeAll(binary_t *b)
{
    if(b->left!=NULL)
        freeAll(b->left);
    if(b->right!=NULL)
        freeAll(b->right);
    //printf("%c ",b->data);
    free(b);
    return;
}

void insertTree(binary_t *b,int loc,char c)
{
    if(loc>b->loc)
    {
        if(b->right==NULL)
        {
            binary_t *next=(binary_t*)malloc(sizeof(binary_t));
            b->right=next;
            next->left=next->right=NULL;
            next->data=c;
            next->loc=loc;
        }
        else insertTree(b->right,loc,c);
    }
    else
    {
        if(b->left==NULL)
        {
            binary_t *next=(binary_t*)malloc(sizeof(binary_t));
            b->left=next;
            next->left=next->right=NULL;
            next->data=c;
            next->loc=loc;
        }
        else insertTree(b->left,loc,c);
    }
    return;
}

