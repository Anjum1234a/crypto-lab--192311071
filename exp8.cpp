#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    char key[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Ciphertext: ");

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
            printf("%c", key[text[i] - 'a']);
        else if(text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", key[text[i] - 'A']);
        else
            printf("%c", text[i]);
    }

    return 0;
}
