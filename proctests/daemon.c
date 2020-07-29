#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printPid()
{
    FILE *fp;
    int PID = 0;
    fp = fopen("/proc/self/stat", "r");
    fscanf(fp, "%d", &PID);
    printf("%d\n", PID);
    fclose(fp);
    return;
}

int main()
{

    daemon(0, 1);
    printPid();
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    while (1)
    {
        /* code */
    }

    return 0;
}