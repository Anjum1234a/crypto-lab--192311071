#include <stdio.h>
#include <string.h>

int main()
{
    char p[100],c[100],d[100];
    int key[100],i,n;

    printf("Enter plaintext: ");
    scanf("%s",p);

    n=strlen(p);

    printf("Enter %d key values (0-25):\n",n);

    for(i=0;i<n;i++)
        scanf("%d",&key[i]);

    for(i=0;i<n;i++)
    {
        c[i]=((p[i]-'A'+key[i])%26)+'A';
        d[i]=((c[i]-'A'-key[i]+26)%26)+'A';
    }

    c[n]='\0';
    d[n]='\0';

    printf("Encrypted text: %s\n",c);
    printf("Decrypted text: %s\n",d);

    return 0;
}
