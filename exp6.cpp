#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[100], plain[100];
    int a, b, i, x;

    printf("Enter ciphertext: ");
    scanf("%s", cipher);

    a = 21;
    b = 9;
    for(i = 0; cipher[i] != '\0'; i++)
    {
        x = cipher[i] - 'A';
        plain[i] = ((5 * (x - b + 26)) % 26) + 'A';
    }

    plain[i] = '\0';

    printf("Decrypted text: %s\n", plain);

    return 0;
}
