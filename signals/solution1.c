#include <stdio.h>
#include <stdlib.h>

int countSymbols(char symbol, char *programm, char *param)
{
    char fullCommand[1024];
    sprintf(fullCommand, "%s %s | grep -o %c | wc -l", programm, param, symbol);
    FILE *resultOut;
    resultOut = popen(fullCommand, "r");
    long res = 0;
    fscanf(resultOut, "%ld", &res);
    pclose(resultOut);
    return res;
}

int main(int argc, char *argv[])
{
    char mySymb = '0';
    printf("%d\n", countSymbols(mySymb, argv[1], argv[2]));
    return 0;
}