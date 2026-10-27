#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    int i, x, y;

    printf("Enter plaintext: ");
    scanf("%s", s);

    printf("Ciphertext: ");

    for(i = 0; s[i] != '\0'; i += 2)
    {
        x = s[i] - 'a';
        y = s[i+1] - 'a';

        printf("%c%c",
        (9*x + 4*y) % 26 + 'a',
        (5*x + 7*y) % 26 + 'a');
    }

    return 0;
}
