#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter key: ");
    scanf("%s", key);

    printf("Encrypted text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        char p = toupper(text[i]) - 'A';
        char k = toupper(key[j]) - 'A';

        printf("%c", (p + k) % 26 + 'A');

        j++;
        if (key[j] == '\0')
            j = 0;
    }

    return 0;
}
