#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

void calculate_the_maximum(int n, int k)
{
    //Write your code here.
    int mand = 0;
    int mor = 0;
    int mxor = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (((i & j) > mand) && ((i & j) < k))
            {
                mand = i & j;
            }
            if (((i | j) > mor) && ((i | j) < k))
            {
                mor = i | j;
            }
            if (((i ^ j) > mxor) && ((i ^ j) < k))
            {
                mxor = i ^ j;
            }
        }
    }
    printf("%d\n%d\n%d\n", mand, mor, mxor);
    return;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}