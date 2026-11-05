#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    char p[100],c[100];
    int a,b,i;

    printf("Enter plaintext: ");
    scanf("%s",p);

    printf("Enter a and b: ");
    scanf("%d%d",&a,&b);

    if(gcd(a,26)!=1)
    {
        printf("Invalid key: Encryption is not one-to-one.");
        return 0;
    }

    for(i=0;p[i]!='\0';i++)
        c[i]=((a*(p[i]-'A')+b)%26)+'A';

    c[i]='\0';

    printf("Encrypted text: %s",c);

    return 0;
}
