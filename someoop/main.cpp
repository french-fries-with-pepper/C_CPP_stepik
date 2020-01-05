#include <iostream>
using namespace std;

struct Foo
{
    void say() const { std::cout << "Foo says: " << msg << "\n"; }

protected:
    Foo(const char *msg) : msg(msg) {}

private:
    const char *msg;
};

struct Foochild : Foo
{
    Foochild(const char *msg)
        : Foo(msg){};
};

Foo get_foo(const char *msg)
{
    Foochild tmp(msg);
    Foo res = tmp;
    return res;
}

void foo_says(const Foo &foo) { foo.say(); }

int main()
{

    string m = "hello, dude";
    char *m2 = "modern";
    Foochild p(m2);
    foo_says(p);

    return 0;
}