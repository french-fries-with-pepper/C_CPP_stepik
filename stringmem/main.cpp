#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *res = new char[new_size];

    if (new_size >= size)
    {
        for (int i = 0; i < size; i++)
        {
            res[i] = str[i];
        }
        delete[] str;
        return res;
    }
    else
    {
        for (int i = 0; i < new_size; i++)
        {
            res[i] = str[i];
        }
        delete[] str;
        return res;
    }
}
char *getline()
{
    int chunk = 15;
    char *res = new char[chunk];
    for (int i = 0;; i++)
    {
        if (i >= chunk)
        {

            res = resize(res, chunk, chunk * 2);
            chunk *= 2;
        }
        char current = '\0';
        cin.get(current);
        if ((current == '\0') || (current == '\n'))
        {
            res[i] = '\0';
            return res;
        }
        res[i] = current;
    }
}
int main()
{

    char *str1 = getline();

    cout << str1 << endl;
    return 0;
}