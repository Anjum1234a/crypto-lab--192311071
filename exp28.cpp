#include <stdio.h>

int power(int a,int x,int q)
{
    int r=1;

    while(x>0)
    {
        r=(r*a)%q;
        x--;
    }

    return r;
}

int main()
{
    int a,q,x,y,A,B,k1,k2;

    printf("Enter public number a and prime q: ");
    scanf("%d%d",&a,&q);

    printf("Enter Alice secret number: ");
    scanf("%d",&x);

    printf("Enter Bob secret number: ");
    scanf("%d",&y);

    A=power(a,x,q);
    B=power(a,y,q);

    k1=power(B,x,q);
    k2=power(A,y,q);

    printf("Alice public value = %d\n",A);
    printf("Bob public value = %d\n",B);
    printf("Alice shared key = %d\n",k1);
    printf("Bob shared key = %d\n",k2);

    if(k1==k2)
        printf("Shared key established successfully");

    return 0;
}
