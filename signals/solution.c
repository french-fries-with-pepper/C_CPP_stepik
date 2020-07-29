#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int c1 = 0;
int c2 = 0;

void mysignal_handler(int signo)
{

    switch (signo)
    {
    case SIGUSR1:
        ++c1;
        break;
    case SIGUSR2:
        ++c2;
        break;
    case SIGTERM:
        printf("%d %d\n", c1, c2);
        exit(0);
    default:
        break;
    }
};

int main()
{

    signal(SIGUSR1, mysignal_handler);
    signal(SIGUSR2, mysignal_handler);
    signal(SIGTERM, mysignal_handler);

    while (1)
    {
        usleep(500000);
    }
    return 0;
}
