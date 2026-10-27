#include <stdio.h>

int main()
{
    char c[1000], key[27];
    int i;

    printf("Enter ciphertext: ");
    scanf(" %999[^\n]", c);

    printf("Enter 26-letter decryption key: ");
    scanf("%26s", key);

    printf("Decrypted message: ");

    for(i = 0; c[i] != '\0'; i++)
    {
        if(c[i] >= 'a' && c[i] <= 'z')
            printf("%c", key[c[i] - 'a']);

        else if(c[i] >= 'A' && c[i] <= 'Z')
        {
            char ch = key[c[i] - 'A'];

            if(ch >= 'a' && ch <= 'z')
                ch = ch - 32;

            printf("%c", ch);
        }
        else
            printf("%c", c[i]);
    }

    printf("\n");
    return 0;
}
