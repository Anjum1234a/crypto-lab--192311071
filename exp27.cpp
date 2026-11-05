#include <stdio.h>

long long power(long long a,int e,int n)
{
    long long r=1;

    while(e>0)
    {
        if(e%2)
            r=(r*a)%n;

        a=(a*a)%n;
        e/=2;
    }

    return r;
}

int main()
{
    int e,n,i;
    long long c;

    printf("Enter public key e and n: ");
    scanf("%d%d",&e,&n);

    printf("Enter encrypted character: ");
    scanf("%lld",&c);

    for(i=0;i<26;i++)
    {
        if(power(i,e,n)==c)
        {
            printf("Character = %c\n",i+'A');
            return 0;
        }
    }

    printf("Character not found\n");

    return 0;
}
