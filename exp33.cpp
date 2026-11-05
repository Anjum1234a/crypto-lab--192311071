#include <stdio.h>
#include <openssl/des.h>

int main()
{
    DES_cblock key = {
        0x13,0x34,0x57,0x79,
        0x9B,0xBC,0xDF,0xF1
    };

    DES_key_schedule ks;

    DES_set_key_unchecked(&key,&ks);

    DES_cblock plain = {
        0x01,0x23,0x45,0x67,
        0x89,0xAB,0xCD,0xEF
    };

    DES_cblock cipher, decrypted;

    DES_ecb_encrypt(&plain,&cipher,&ks,DES_ENCRYPT);

    printf("Encrypted Data: ");
    for(int i=0;i<8;i++)
        printf("%02X ",cipher[i]);

    DES_ecb_encrypt(&cipher,&decrypted,&ks,DES_DECRYPT);

    printf("\nDecrypted Data: ");
    for(int i=0;i<8;i++)
        printf("%02X ",decrypted[i]);

    return 0;
}
