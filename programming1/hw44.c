#include <stdio.h>
#include <math.h>

void f1(int,int,int,int,double*,double*);
void f2(int,int,int,int,int*,int*,int*,int*);

int main(void)
{
    int x1,y1,x2,y2;
    int m1=0,m2=0,b1=0,b2=0;
    double m=0.0l,b=0.0l;
    char c;
    //printf("Program Start:\n");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    while((c=getchar())!=EOF && c!='\n')
    {
        printf("Error!");
        return 0;
    }
    if(x1==x2 && y1==y2)
    {
        printf("Error!");
        return 0;
    }
    f1(x1,y1,x2,y2,&m,&b);
    f2(x1,y1,x2,y2,&m1,&m2,&b1,&b2);
    return 0;
}

void f1(int x1,int y1,int x2,int y2,double* m, double* b)
{
    int im,ib;
    if(y1==y2)
    {
        printf("y=%d\n",y1);
        return;
    }
    else if(x1==x2)
    {
        printf("x=%d\n",x1);
        return;
    }
    if(abs(y1-y2)%abs(x1-x2)==0)        //若為整數則以整數型態輸出
    {
        im=(y1-y2)/(x1-x2);
        if(im==1)
        {
            if(abs(x2*y1-x1*y2)%abs(x2-x1)==0)
            {
                ib=(x2*y1-x1*y2)/(x2-x1);
                printf("y=x%+d\n",im,ib);
            }
            else
            {
                *b=(double)(x2*y1-x1*y2)/(double)(x2-x1);
                printf("y=x%+.2f\n",im,*b);
            }
        }
        else if(im==-1)
        {
            if(abs(x2*y1-x1*y2)%abs(x2-x1)==0)
            {
                ib=(x2*y1-x1*y2)/(x2-x1);
                printf("y=-x%+d\n",ib);
            }
            else
            {
                *b=(double)(x2*y1-x1*y2)/(double)(x2-x1);
                printf("y=-x%+.2f\n",*b);
            }
        }
        else
        {
            if(abs(x2*y1-x1*y2)%abs(x2-x1)==0)
            {
                ib=(x2*y1-x1*y2)/(x2-x1);
                printf("y=%dx%+d\n",im,ib);
            }
            else
            {
                *b=(double)(x2*y1-x1*y2)/(double)(x2-x1);
                printf("y=%dx%+.2f\n",im,*b);
            }
        }
    }
    else
    {
        *m=(double)(y1-y2)/(double)(x1-x2);
        if(abs(x2*y1-x1*y2)%abs(x2-x1)==0)
        {
            ib=(x2*y1-x1*y2)/(x2-x1);
            printf("y=%.2fx%+d\n",*m,ib);
        }
        else
        {
            *b=(double)(x2*y1-x1*y2)/(double)(x2-x1);
            printf("y=%.2fx%+.2f\n",*m,*b);
        }
    }
    return;
}

void f2(int x1,int y1,int x2,int y2,int* m1,int* m2,int* b1,int* b2)
{
    int m,b;
    if(x1==x2)
    {
        printf("x=%d\n",x1);
        return;
    }
    else if(y1==y2)
    {
        printf("y=%d\n",y1);
        return;
    }
    *m1=(y1-y2);
    *m2=(x1-x2);
    *b1=(x2*y1-x1*y2);
    *b2=(x2-x1);
    if(*m2<0)
    {
        *m1=-(*m1);
        *m2=-(*m2);
    }
    if(*b2<0)
    {
        *b1=-(*b1);
        *b2=-(*b2);
    }
    if((*m1)%(*m2)==0)
    {
        if(*m1==*m2)
        {
            if(*b1 % *b2==0)printf("y=x%+d\n",(*b1)/(*b2));
            else printf("y=x%+d/%d\n",*b1,*b2);
        }
        else if(*m1==-*m2)
        {
            if(*b1 % *b2==0)printf("y=-x%+d\n",*b1 / *b2);
            else printf("y=-x%+d/%d\n",*b1,*b2);
        }
        else
        {
            if(*b1 % *b2==0)printf("y=%dx%+d\n",(*m1)/(*m2),(*b1)/(*b2));
            else printf("y=%dx%+d/%d\n",(*m1)/(*m2),*b1,*b2);
        }
    }
    else
    {
        if(*b1 % *b2==0)printf("y=%d/%dx%+d\n",*m1,*m2,(*b1)/(*b2));
        else printf("y=%d/%dx%+d/%d\n",*m1,*m2,*b1,*b2);
    }
    return;
}

