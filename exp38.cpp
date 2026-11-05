#include <stdio.h>

int main()
{
    int a,b,c,d;
    int c1,c2,c3,c4;

    printf("Enter ciphertext for plaintext AB: ");
    scanf("%d%d",&c1,&c2);

    printf("Enter ciphertext for plaintext BA: ");
    scanf("%d%d",&c3,&c4);

    /* Plaintext AB = (0,1)
       Plaintext BA = (1,0) */

    a=c3;
    c=c4;
    b=c1;
    d=c2;

    printf("\nRecovered Hill key matrix:\n");
    printf("%d %d\n",a,b);
    printf("%d %d\n",c,d);

    return 0;
}
