#include <stdio.h>
#include <string.h>

int main()
{
    char c[1000],temp[1000];
    char eng[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26]={0},i,j;
    int order[26];

    printf("Enter ciphertext:\n");
    fgets(c,sizeof(c),stdin);

    for(i=0;c[i];i++)
        if(c[i]>='A' && c[i]<='Z')
            count[c[i]-'A']++;
        else if(c[i]>='a' && c[i]<='z')
            count[c[i]-'a']++;

    for(i=0;i<26;i++)
        order[i]=i;

    for(i=0;i<26;i++)
        for(j=i+1;j<26;j++)
            if(count[order[j]]>count[order[i]])
            {
                int t=order[i];
                order[i]=order[j];
                order[j]=t;
            }

    printf("\nTop 10 possible plaintexts:\n");

    for(int k=0;k<10;k++)
    {
        strcpy(temp,c);

        for(i=0;temp[i];i++)
        {
            if(temp[i]>='A' && temp[i]<='Z')
                temp[i]=eng[(j=0)+0]; /* replaced below */
        }

        for(i=0;i<26;i++)
        {
            char from='A'+order[i];
            char to=eng[(i+k)%26];

            for(j=0;temp[j];j++)
                if(temp[j]==from)
                    temp[j]=to;
        }

        printf("%d. %s\n",k+1,temp);
    }

    return 0;
}
