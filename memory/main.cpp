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

int main()
{

    char *m = new char[1000];

    m[995] = 7;

    m = resize(m, 1000, 1500);

    m[1350] = 8;

    cout << m[995] << " " << m[1350] << endl;

    return 0;
}