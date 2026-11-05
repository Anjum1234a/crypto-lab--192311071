#include <stdio.h>

/* Use the same S-DES functions and tables
   given in Question 22. */

int P10[]={3,5,2,7,4,10,1,9,8,6};
int P8[]={6,3,7,4,8,5,10,9};
int IP[]={2,6,3,1,4,8,5,7};
int IPI[]={4,1,3,5,7,2,8,6};
int EP[]={4,1,2,3,2,3,4,1};
int P4[]={2,4,3,1};

int S0[4][4]={{1,0,3,2},{3,2,1,0},
              {0,2,1,3},{3,1,3,2}};
int S1[4][4]={{0,1,2,3},{2,0,1,3},
              {3,0,1,0},{2,1,0,3}};

int keys[2];

int perm(int x,int *p,int n,int len)
{
    int r=0,i;
    for(i=0;i<len;i++)
        r=(r<<1)|((x>>(n-p[i]))&1);
    return r;
}

void generate(int k)
{
    int x=perm(k,P10,10,10);
    int l=x>>5,r=x&31;

    l=((l<<1)|(l>>4))&31;
    r=((r<<1)|(r>>4))&31;
    keys[0]=perm((l<<5)|r,P8,10,8);

    l=((l<<2)|(l>>3))&31;
    r=((r<<2)|(r>>3))&31;
    keys[1]=perm((l<<5)|r,P8,10,8);
}

int sb(int x,int s[4][4])
{
    int row=((x&8)>>2)|(x&1);
    int col=(x>>1)&3;
    return s[row][col];
}

int f(int r,int k)
{
    int x=perm(r,EP,4,8)^k;
    return perm((sb(x>>4,S0)<<2)|sb(x&15,S1),P4,4,4);
}

int fk(int x,int k)
{
    return (((x>>4)^f(x&15,k))<<4)|(x&15);
}

int encrypt(int x)
{
    x=perm(x,IP,8,8);
    x=fk(x,keys[0]);
    x=((x&15)<<4)|(x>>4);
    x=fk(x,keys[1]);
    return perm(x,IPI,8,8);
}

int main()
{
    int p[]={1,2,4},c[3],d[3];
    int i,counter=0;

    generate(509);

    for(i=0;i<3;i++)
        c[i]=p[i]^encrypt(counter++);

    counter=0;

    for(i=0;i<3;i++)
        d[i]=c[i]^encrypt(counter++);

    printf("Encrypted CTR:\n");
    for(i=0;i<3;i++)
        printf("%08d\n",0),printf("%d ",c[i]);

    printf("\nDecrypted CTR:\n");
    for(i=0;i<3;i++)
        printf("%d ",d[i]);

    return 0;
}
