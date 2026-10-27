
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[1000], plain[1000];
    int score[26] = {0};
    int key, i, j, top, temp;
    int used[26] = {0};

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("How many possible plaintexts do you want? ");
    scanf("%d", &top);

    if (top < 1) top = 1;
    if (top > 26) top = 26;

    for (key = 0; key < 26; key++) {
        score[key] = 0;

        for (i = 0; cipher[i] != '\0'; i++) {
            if (isalpha((unsigned char)cipher[i])) {
                char ch = toupper((unsigned char)cipher[i]);
                plain[i] = (ch - 'A' - key + 26) % 26 + 'A';
            } else {
                plain[i] = cipher[i];
            }
        }
        plain[i] = '\0';

        for (i = 0; plain[i] != '\0'; i++) {
            if (isalpha((unsigned char)plain[i])) {
                char ch = tolower((unsigned char)plain[i]);

                if (ch == 'e') score[key] += 13;
                else if (ch == 't') score[key] += 9;
                else if (ch == 'a' || ch == 'o') score[key] += 8;
                else if (ch == 'i' || ch == 'n') score[key] += 7;
                else if (ch == 's' || ch == 'h' || ch == 'r') score[key] += 6;
                else if (ch == 'd' || ch == 'l') score[key] += 4;
                else score[key] += 1;
            }
        }
    }

    printf("\nTop %d possible plaintexts:\n", top);

    for (i = 0; i < top; i++) {
        int best = -1;

        for (j = 0; j < 26; j++) {
            if (!used[j] && (best == -1 || score[j] > score[best]))
                best = j;
        }

        used[best] = 1;

        printf("\nKey %d: ", best);
        for (j = 0; cipher[j] != '\0'; j++) {
            if (isalpha((unsigned char)cipher[j])) {
                char ch = toupper((unsigned char)cipher[j]);
                printf("%c", (ch - 'A' - best + 26) % 26 + 'A');
            } else {
                printf("%c", cipher[j]);
            }
        }
        printf(" (Score: %d)\n", score[best]);
    }

    return 0;
}
