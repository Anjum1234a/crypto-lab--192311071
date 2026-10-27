#include <stdio.h>

int main(void)
{
    printf("ECB Mode:\n");
    printf("An error in C1 affects only P1.\n");
    printf("Other plaintext blocks remain unaffected.\n");

    printf("\nCBC Mode:\n");
    printf("An error in C1 affects P1 and P2.\n");
    printf("P1 becomes corrupted; the corresponding bit in P2 flips.\n");
    printf("P3 and later plaintext blocks remain unaffected.\n");

    printf("\nIf an error occurs in source plaintext P1:\n");
    printf("C1 and all subsequent ciphertext blocks are affected.\n");
    printf("At the receiver, all plaintext blocks may be corrupted.\n");

    return 0;
}
