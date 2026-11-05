#include <stdio.h>

int E(int x)
{
    return (5*x+7)%256;
}

int D(int x)
{
    return (((x-7+256)*205)%256);
}

int main()
{
    int p[4],e[4],c[4],f[4];
    int key=5,iv=10,prev;
    int i;

    printf("Enter 4 plaintext blocks (0-255):\n");

    for(i=0;i<4;i++)
        scanf("%d",&p[i]);

    printf("\nECB:\n");
    for(i=0;i<4;i++)
    {
        e[i]=E(p[i]);
        printf("%d ",e[i]);
    }

    printf("\nCBC:\n");
    prev=iv;

    for(i=0;i<4;i++)
    {
        c[i]=E(p[i]^prev);
        prev=c[i];
        printf("%d ",c[i]);
    }

    printf("\nCFB:\n");
    prev=iv;

    for(i=0;i<4;i++)
    {
        f[i]=p[i]^E(prev);
        prev=f[i];
        printf("%d ",f[i]);
    }

    return 0;
}
