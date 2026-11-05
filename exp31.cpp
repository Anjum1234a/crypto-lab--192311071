#include <stdio.h>
#include <stdint.h>

void shift(uint8_t *a, int n, uint8_t *b)
{
    int i, carry = 0, next;

    for(i=n-1; i>=0; i--)
    {
        next = (a[i] >> 7) & 1;
        b[i] = (a[i] << 1) | carry;
        carry = next;
    }
}

int main()
{
    uint8_t L[16], K1[16], K2[16];
    int i, carry;

    printf("Enter 16 bytes of L in hexadecimal:\n");

    for(i=0; i<16; i++)
        scanf("%hhx", &L[i]);

    shift(L,16,K1);

    if(L[0] & 0x80)
        K1[15] ^= 0x87;

    shift(K1,16,K2);

    if(K1[0] & 0x80)
        K2[15] ^= 0x87;

    printf("Subkey K1: ");
    for(i=0; i<16; i++)
        printf("%02X ",K1[i]);

    printf("\nSubkey K2: ");
    for(i=0; i<16; i++)
        printf("%02X ",K2[i]);

    return 0;
}
