#include <stdio.h>

int main()
{
    int p[2][2], c[2][2];
    int a, b, d, e;

    printf("Enter plaintext matrix (4 numbers): ");
    scanf("%d%d%d%d", &p[0][0], &p[0][1],
          &p[1][0], &p[1][1]);

    printf("Enter ciphertext matrix (4 numbers): ");
    scanf("%d%d%d%d", &c[0][0], &c[0][1],
          &c[1][0], &c[1][1]);

    a = (c[0][0] * p[1][1] - c[0][1] * p[1][0]);
    b = (c[0][1] * p[0][0] - c[0][0] * p[0][1]);
    d = (c[1][0] * p[1][1] - c[1][1] * p[1][0]);
    e = (c[1][1] * p[0][0] - c[1][0] * p[0][1]);

    printf("Key calculation values:\n");
    printf("%d %d\n", a, b);
    printf("%d %d\n", d, e);

    printf("Reduce values modulo 26 to continue.\n");

    return 0;
}
