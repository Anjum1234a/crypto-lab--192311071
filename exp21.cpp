#include <stdio.h>

int main()
{
    int p[4], key, iv, i;
    int ecb[4], cbc[4], cfb[4];

    printf("Enter 4 plaintext bytes (0-255):\n");
    for(i=0; i<4; i++)
        scanf("%d", &p[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter IV: ");
    scanf("%d", &iv);

    for(i=0; i<4; i++)
    {
        ecb[i] = p[i] ^ key;
        cbc[i] = p[i] ^ key ^ iv;
        iv = cbc[i];
    }

    iv = 10;

    for(i=0; i<4; i++)
    {
        cfb[i] = p[i] ^ (key ^ iv);
        iv = cfb[i];
    }

    printf("\nECB Output: ");
    for(i=0; i<4; i++)
        printf("%d ", ecb[i]);

    printf("\nCBC Output: ");
    for(i=0; i<4; i++)
        printf("%d ", cbc[i]);

    printf("\nCFB Output: ");
    for(i=0; i<4; i++)
        printf("%d ", cfb[i]);

    return 0;
}
