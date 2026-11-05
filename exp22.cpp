#include <stdio.h>

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

int perm(int x,int *p,int n,int len)
{
    int r=0,i;
    for(i=0;i<len;i++)
        r=(r<<1)|((x>>(n-p[i]))&1);
    return r;
}

int keys[2];

void generate(int k)
{
    int x=perm(k,P10,10,10);
    int l=(x>>5)&31,r=x&31;

    l=((l<<1)|(l>>4))&31;
    r=((r<<1)|(r>>4))&31;

    keys[0]=perm((l<<5)|r,P8,10,8);

    l=((l<<2)|(l>>3))&31;
    r=((r<<2)|(r>>3))&31;

    keys[1]=perm((l<<5)|r,P8,10,8);
}

int sbox(int x,int s[4][4])
{
    int row=((x&8)>>2)|(x&1);
    int col=(x>>1)&3;
    return s[row][col];
}

int f(int r,int k)
{
    int x=perm(r,EP,4,8)^k;
    int a=sbox((x>>4)&15,S0);
    int b=sbox(x&15,S1);
    return perm((a<<2)|b,P4,4,4);
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

int decrypt(int x)
{
    x=perm(x,IP,8,8);
    x=fk(x,keys[1]);
    x=((x&15)<<4)|(x>>4);
    x=fk(x,keys[0]);
    return perm(x,IPI,8,8);
}

int main()
{
    int p[2]={1,35},c[2],d[2];
    int iv=170,prev=iv,i;

    generate(509);

    for(i=0;i<2;i++)
    {
        c[i]=encrypt(p[i]^prev);
        prev=c[i];
    }

    prev=iv;

    for(i=0;i<2;i++)
    {
        d[i]=decrypt(c[i])^prev;
        prev=c[i];
    }

    printf("Encrypted CBC:\n");
    for(i=0;i<2;i++)
        printf("%08d\n",0),printf("%d\n",c[i]);

    printf("Decrypted CBC:\n");
    for(i=0;i<2;i++)
        printf("%d ",d[i]);

    return 0;
}
