#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    scanf("%s", s);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    for(i = 0; s[i] != '\0'; i++)
    {
        p = s[i] - 'A';
        c = (a * p + b) % 26;
        printf("%c", c + 'A');
    }

    return 0;
}
