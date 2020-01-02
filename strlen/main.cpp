#include <iostream>
using namespace std;

unsigned strlen(const char *str)
{
    unsigned size = 0;
    for (;;)
    {
        if (*str == '\0')
        {
            return size;
        }
        ++str;
        ++size;
    }
}

void strcat(char *to, const char *from)
{
    unsigned firstSize = strlen(to);
    unsigned secondSize = strlen(from);

    to += firstSize;

    for (;;)
    {
        if (*from == '\0')
        {
            *to = '\0';
            return;
        }
        *to = *from;
        ++to;
        ++from;
    }
}

/* bool isStringSame(char *str1, char *str2)
{
    for (;;)
    {
        if (*str1 != *str2)
        {
            return false;
        }
        ++str1;
        ++str2;
        if ((*str1 == '\0') && (*str2 == '\0'))
        {
            return true;
        }
    }
} */

bool isStringSame(char *str1, char *str2)
{
    for (;;)
    {
        if (*str1 != *str2)
        {
            return false;
        }
        ++str1;
        ++str2;
        if ((*str1 == '\0') && (*str2 == '\0'))
        {
            return true;
        }
    }
}

int strstr(const char *text, const char *pattern)
{

    //int pointer = 0;
    unsigned size = strlen(text);
    unsigned patternSize = strlen(pattern);

    if (patternSize == 0)
    {
        return 0;
    }

    if ((size == 0) || (size < patternSize))
    {
        return -1;
    }

    cout << text[1] << endl;
    cout << pattern[0] << endl;

    return -1;
}

int main()
{
    char str1[] = "zaba";
    char str2[] = "b";

    cout << strstr(str1, str2) << endl;
    return 0;
}