#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char a[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };

    char s[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    int i, j, r1, c1, r2, c2;

    printf("Encrypted message: ");

    for(i = 0; s[i] != '\0'; i += 2)
    {
        char x = s[i], y = s[i+1];

        if(x == 'J') x = 'I';
        if(y == 'J') y = 'I';

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
