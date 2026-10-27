
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipher[] = "QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD";
char plain[1000];

int main() {
    char text[1000];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    char map[26];
    int i, j, top;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if (top < 1) top = 1;
    if (top > 10) top = 10;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i]))
            count[toupper((unsigned char)text[i]) - 'A']++;
    }

    for (i = 0; i < 26; i++)
        map[i] = '?';

    for (i = 0; i < 26; i++) {
        int max = -1, pos = -1;

        for (j = 0; j < 26; j++) {
            if (count[j] > max) {
                max = count[j];
                pos = j;
            }
        }

        if (pos >= 0) {
            map[pos] = freq[i];
            count[pos] = -1;
        }
    }

    printf("\nPossible plaintext (frequency estimate):\n");

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            char ch = map[toupper((unsigned char)text[i]) - 'A'];
            if (islower((unsigned char)text[i]))
                ch = tolower((unsigned char)ch);
            printf("%c", ch);
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n\nNote: This simple program produces one frequency-based guess.\n");
    printf("It does not generate %d distinct ranked plaintexts.\n", top);

    return 0;
}
