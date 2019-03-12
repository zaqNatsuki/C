#include <stdio.h>
#include <math.h>

float getFloat(float);

int main(void)
{
    float a=0,b=0,c=0;
    float x1=0,x2=0,x12=0,x22=0,t=0;
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    t=b*b-4*a*c;
    if(t>=0)
    {
        x1=(-b+sqrt(t))/(2*a);
        x2=(-b-sqrt(t))/(2*a);
        x1=getFloat(x1);
        x2=getFloat(x2);
        printf("%.1f\n",x1);
        printf("%.1f\n",x2);
    }
    else
    {
        x1=-b/(2*a);
        x1=getFloat(x1);
        x2=x1;
        x12=sqrt(-t)/(2*a);
        x12=getFloat(x12);
        x22=-x12;
        if(x12>=0)
        {
            printf("%.1f%+.1fi\n",x1,x12);
            printf("%.1f%+.1fi\n",x2,x22);
        }
        else
        {
            printf("%.1f%+.1fi\n",x1,x22);
            printf("%.1f%+.1fi\n",x2,x12);
        }
    }
    return 0;
}

float getFloat(float n)
{
    int sign=1;
    if(n<0)
    {
        n=-n;
        sign=-1;
    }
    n=sign*(floor(n*10)/10);
    return n;
}
