#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    scanf("%s", text);

    n = strlen(text);

    printf("Enter %d key numbers (0-25): ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    printf("Ciphertext: ");

    for(i = 0; i < n; i++)
    {
        printf("%c", (text[i] - 'A' + key[i]) % 26 + 'A');
    }

    return 0;
}
