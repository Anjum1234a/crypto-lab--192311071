#include <stdio.h>

int main()
{
    char s[100];
    int i, x, y;

    printf("Enter ciphertext: ");
    scanf("%s", s);

    printf("Plaintext: ");

    for(i = 0; s[i] != '\0'; i += 2)
    {
        x = s[i] - 'a';
        y = s[i+1] - 'a';

        printf("%c%c",
        (5*x + 12*y) % 26 + 'a',
        (15*x + 25*y) % 26 + 'a');
    }

    return 0;
}
