#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main(void)
{
    DES_cblock key1 = {1,2,3,4,5,6,7,8};
    DES_cblock key2 = {9,10,11,12,13,14,15,16};
    DES_cblock key3 = {17,18,19,20,21,22,23,24};

    DES_key_schedule ks1, ks2, ks3;

    DES_set_key_unchecked(&key1, &ks1);
    DES_set_key_unchecked(&key2, &ks2);
    DES_set_key_unchecked(&key3, &ks3);

    unsigned char plaintext[16] = "HELLO CBC MODE!";
    unsigned char ciphertext[16] = {0};

    DES_cblock iv = {0,0,0,0,0,0,0,0};

    DES_ede3_cbc_encrypt(
        plaintext,
        ciphertext,
        16,
        &ks1, &ks2, &ks3,
        &iv,
        DES_ENCRYPT
    );

    printf("Ciphertext (hex):\n");
    for (int i = 0; i < 16; i++)
        printf("%02X ", ciphertext[i]);

    printf("\n");
    return 0;
}
