#include <stdio.h>

int main()
{
    int p=11,q=13;
    int n=p*q;
    int phi=(p-1)*(q-1);

    int e1=7,d1=103;
    int e2=11,d2=71;

    printf("Original RSA Keys\n");
    printf("n = %d\n",n);
    printf("e = %d\n",e1);
    printf("d = %d\n",d1);

    printf("\nNew RSA Keys\n");
    printf("n = %d\n",n);
    printf("e = %d\n",e2);
    printf("d = %d\n",d2);

    printf("\nSame modulus is reused.\n");
    printf("Therefore, generating new keys is unsafe.\n");

    return 0;
}
