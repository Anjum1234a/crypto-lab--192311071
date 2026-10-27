#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int shifts[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };
    uint32_t C = 0x0F0F0F0;
    uint32_t D = 0x00FF00F;
    printf("DES Key Generation\n");

    for (int round = 0; round < 16; round++) {
        int s = shifts[round];
        C = ((C << s) | (C >> (28 - s))) & 0x0FFFFFFF;
        D = ((D << s) | (D >> (28 - s))) & 0x0FFFFFFF;

        printf("Round %2d: C = %07X, D = %07X\n",
               round + 1, C, D);
    }

    return 0;
}
