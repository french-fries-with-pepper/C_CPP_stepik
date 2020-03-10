#include <stdio.h>
#include <stdlib.h>

long long makeSumInNewPlace(long long shm1, long long shm2, long long resAddr)
{

    return resAddr;
}

int main(int argc, char *argv[])
{
    long long myAddr = 54321;
    if (argc < 3)
    {
        printf("too few arguments\n");
        return 1;
    }
    else
    {
        printf("%lld\n", makeSumInNewPlace(atoll(argv[1]), atoll(argv[2]), myAddr));
    }

    return 0;
}