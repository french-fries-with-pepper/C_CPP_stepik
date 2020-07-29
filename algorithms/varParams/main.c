#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int count, ...)
{
    int res = 0;
    va_list argList;
    va_start(argList, count);

    for (size_t i = 0; i < count; i++)
    {
        res += va_arg(argList, int);
    }
    va_end(argList);
    return res;
}

int min(int count, ...)
{
    int res = 1 << 31 - 1;
    va_list argList;
    va_start(argList, count);

    for (size_t i = 0; i < count; i++)
    {
        int cur = va_arg(argList, int);
        if (cur < res)
        {
            res = cur;
        }
    }

    va_end(argList);
    return res;
}

int max(int count, ...)
{

    int res = 1 << 31;
    va_list argList;
    va_start(argList, count);

    for (size_t i = 0; i < count; i++)
    {
        int cur = va_arg(argList, int);
        if (cur > res)
        {
            res = cur;
        }
    }

    va_end(argList);
    return res;
}

int main()
{

    printf("max: %d\n", max(4, 1, 5, 7, 99));
    printf("min: %d\n", min(3, 0, 8, 9));
    printf("sum: %d\n", sum(4, 5, 5, 4, 1));

    return 0;
}