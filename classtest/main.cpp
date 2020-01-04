#include <iostream>
using namespace std;

struct Cls
{
    Cls(char c, double d, int i);

private:
    char c;
    double d;
    int i;
};

struct Cls_public
{
    Cls_public(char c, double d, int i);

public:
    char c;
    double d;
    int i;
};

char &get_c(Cls &cls)
{
    // void *voidptr = static_cast<void *>(&cls);           /*Преобразуем указатель типа Сls* к типу void*. Как бы между делом замечаем поразительное внешнее сходство с непутевым братом.*/
    // struct ClsPubl *p = static_cast<ClsPubl *>(voidptr); /*Преобразуем указатель типа void* к типу ClsPubl*, чтобы получить доступ к полям и методам. Далее говорим, что у нас таки есть свидетель, опознавший вашего брата (блеф, но иначе никак)! Но может это были вы? Что будет если вас посадят вместо него за его преступление? Как потом жить вашей семье? Ведь у них все отнимут в качестве компенсации!*/
    // return p->c;
}

double &get_d(Cls &cls)
{
    /* ... */
}

int &get_i(Cls &cls)
{
    /* ... */
}

int main()
{
    Cls obj(99, 0.2, 3);

    struct ClsPubl *p = static_cast<ClsPubl *>(static_cast<void *>((&obj)));
    cout << p->c << " " << p->d << " " << p->i;

    return 0;
}