#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int n;
    scanf("%d", &n);
    int size = n * 2 - 1;

    for (int i = -n + 1; i < n; i++)
    {
        for (int j = -n + 1; j < n; j++)
        {
            int res;
            res = max(abs(i), abs(j)) + 1;
            printf("%d ", res);
        }
        printf("\n");
    }

    return 0;
}