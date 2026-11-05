#include <stdio.h>

int main()
{
    int block=1024;
    int state=1600;
    int lane=64;

    int capacity=state-block;
    int total_lanes=capacity/lane;

    printf("State size = %d bits\n",state);
    printf("Block size = %d bits\n",block);
    printf("Capacity = %d bits\n",capacity);
    printf("Lane size = %d bits\n",lane);

    printf("Number of zero lanes = %d\n",total_lanes);

    printf("After absorbing first block:\n");
    printf("Rate lanes = 16 nonzero lanes\n");
    printf("Capacity lanes = 9 zero lanes\n");

    printf("Without permutation, capacity lanes remain zero.\n");

    return 0;
}
