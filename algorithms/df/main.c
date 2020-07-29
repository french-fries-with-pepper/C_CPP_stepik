#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int digits[10] = {0};

    char p;
    while (scanf("%c", &p) == 1)
    {

        if (p >= '0' && p <= "9")
        {
            ++digits[p - '0'];
        }
        ++p;
    }

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", digits[i]);
    }
    printf("\n");
    return 0;
}
