#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char plain[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i, j;

    printf("Enter text (Capital letters only): ");
    gets(text);

    for(i = 0; text[i] != '\0'; i++) {
        for(j = 0; j < 26; j++) {
            if(text[i] == plain[j]) {
                text[i] = cipher[j];
                break;
            }
        }
    }

    printf("Encrypted Text: %s", text);

    return 0;
}
