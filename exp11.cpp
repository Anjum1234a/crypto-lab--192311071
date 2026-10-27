#include <stdio.h>
#include <math.h>

int main()
{
    double keys, unique;

    keys = 1;
    for(int i = 1; i <= 25; i++)
        keys = keys * i;

    unique = keys / (25 * 2);

    printf("Total possible keys = %.0f\n", keys);
    printf("Approximate power of 2 = 2^%.0f\n",
           log(keys) / log(2));
    printf("Effectively unique keys = %.0f\n", unique);
    printf("Unique keys approximately = 2^%.0f\n",
           log(unique) / log(2));

    return 0;
}
