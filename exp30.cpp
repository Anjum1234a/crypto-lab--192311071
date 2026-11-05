#include <stdio.h>

int encrypt(int x)
{
    return (5*x+7)%256;
}

int main()
{
    int X,T,Y,MAC;

    printf("Enter one block message X: ");
    scanf("%d",&X);

    T=encrypt(X);

    Y=X^T;

    MAC=encrypt(encrypt(X)^Y);

    printf("One block MAC = %d\n",T);
    printf("Second block = %d\n",Y);
    printf("Two block MAC = %d\n",MAC);

    if(T==MAC)
        printf("Both MAC values are equal");

    return 0;
}
