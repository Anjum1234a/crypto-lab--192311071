#include <stdio.h>
#include <string.h>

int main()
{
    char a[5][5] = {
        {'M','O','N','A','R'},
        {'C','H','Y','B','D'},
        {'E','F','G','I','K'},
        {'L','P','Q','S','T'},
        {'U','V','W','X','Z'}
    };
    char s[20];
    int i, j, r1, c1, r2, c2;

    printf("Enter plaintext: ");
    scanf("%s", s);

    for(i = 0; s[i] != '\0'; i += 2)
    {
        char x = s[i], y = s[i+1];

        for(j = 0; j < 25; j++)
        {
            if(a[j/5][j%5] == x)
                r1 = j/5, c1 = j%5;
            if(a[j/5][j%5] == y)
                r2 = j/5, c2 = j%5;
        }

        if(r1 == r2)
            printf("%c%c", a[r1][(c1+1)%5],
                            a[r2][(c2+1)%5]);
        else if(c1 == c2)
            printf("%c%c", a[(r1+1)%5][c1],
                            a[(r2+1)%5][c2]);
        else
            printf("%c%c", a[r1][c2], a[r2][c1]);
    }

    return 0;
}
