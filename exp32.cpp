#include <stdio.h>

int main()
{
    int p=23,q=11,g=4;
    int x=3,h=7;
    int k1=2,k2=5;
    int r1,s1,r2,s2;

    int y=1;
    int i;

    for(i=0;i<x;i++)
        y=(y*g)%p;

    r1=1;
    for(i=0;i<k1;i++)
        r1=(r1*g)%p;
    r1=r1%q;

    s1=(h+x*r1)%q;

    r2=1;
    for(i=0;i<k2;i++)
        r2=(r2*g)%p;
    r2=r2%q;

    s2=(h+x*r2)%q;

    printf("Public key = %d\n",y);

    printf("First signature: (%d,%d)\n",r1,s1);
    printf("Second signature: (%d,%d)\n",r2,s2);

    printf("Same message, different k values.\n");
    printf("Therefore signatures are different.\n");

    return 0;
}
