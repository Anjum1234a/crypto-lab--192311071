#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];
    char english[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int freq[26]={0};
    int order[26];
    int i,j;

    printf("Enter ciphertext:\n");
    fgets(text,sizeof(text),stdin);

    for(i=0;text[i];i++)
    {
        if(text[i]>='A' && text[i]<='Z')
            freq[text[i]-'A']++;
    }

    for(i=0;i<26;i++)
        order[i]=i;

    for(i=0;i<26;i++)
        for(j=i+1;j<26;j++)
            if(freq[order[j]]>freq[order[i]])
            {
                int t=order[i];
                order[i]=order[j];
                order[j]=t;
            }

    printf("\nFrequency order:\n");

    for(i=0;i<26;i++)
        printf("%c ",order[i]+'A');

    printf("\n\nEnglish frequency order:\n%s\n",english);

    printf("\nPossible plaintext mapping:\n");

    for(i=0;i<26;i++)
        printf("%c -> %c\n",order[i]+'A',english[i]);

    return 0;
}
