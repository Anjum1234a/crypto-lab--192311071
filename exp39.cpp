#include <stdio.h>
#include <string.h>

int main()
{
    char c[1000],p[1000];
    int i,k;

    printf("Enter ciphertext: ");
    fgets(c,sizeof(c),stdin);

    printf("\nPossible plaintexts:\n");

    for(k=0;k<26;k++)
    {
        strcpy(p,c);

        for(i=0;p[i];i++)
        {
            if(p[i]>='A' && p[i]<='Z')
                p[i]=(p[i]-'A'-k+26)%26+'A';

            else if(p[i]>='a' && p[i]<='z')
                p[i]=(p[i]-'a'-k+26)%26+'a';
        }

        printf("Key %2d: %s",k,p);
    }

    return 0;
}
