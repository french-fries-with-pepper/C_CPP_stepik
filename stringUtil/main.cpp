#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
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
    int delta = 15;
    char *res = new char[chunk];
    for (int i = 0;; i++)
    {
        if (i >= chunk)
        {

            res = resize(res, chunk, chunk + delta);
            chunk += delta;
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

struct String
{

    // constructor #1
    String(const char *str = "")
    {
        size_t s = strlen(str);
        this->size = s;
        char *res = new char[s + 1];
        strcpy(res, str);
        this->str = res;
    };

    // constructor #2
    String(size_t n, char c)
    {
        this->size = n;
        char *res = new char[n + 1];
        for (int i = 0; i < n; i++)
        {
            res[i] = c;
        }
        res[n] = '\0';
        this->str = res;
    };
    // destructor
    ~String()
    {
        delete[] this->str;
    }
    // copy constructor
    String(const String &other)
        : size(other.size), str(new char[size + 1])
    {
        for (size_t i = 0; i < size; i++)
        {

            str[i] = other.str[i];
        }

        str[size] = '\0';
    };

    //  '=' constructor
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] str;
            size = other.size;
            str = new char[size + 1];
            strcpy(str, other.str);
            str[size] = '\0';
        }
        return *this;
    }

    void append(String &other)
    {
        size_t sizeFirst = this->size;
        size_t sizeSecond = other.size;

        char *res = new char[sizeFirst + sizeSecond + 1];
        strcpy(res, this->str);
        strcpy(&res[sizeFirst], other.str);

        delete[] this->str;
        this->str = res;
        this->size = sizeFirst + sizeSecond;
        return;
    }

    size_t size;
    char *str;
};

int main()
{

    char *str1 = getline();
    String w = "world";
    String s1(str1);
    String s2 = s1;
    s2.append(w);
    s1 = s2;

    //s1.append(s1);

    cout << s1.str << endl;

    return 0;
}