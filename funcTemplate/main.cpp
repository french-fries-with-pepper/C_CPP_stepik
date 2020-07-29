#include <cstddef>
#include <iostream>

using namespace std;

// Параметры функции copy_n идут в следующем
// порядке:
//   1. целевой массив
//   2. массив источник
//   3. количество элементов, которые нужно
//      скопировать
//
// Вам нужно реализовать только функцию copy_n,
// чтобы ее можно было вызвать так, как показано
// в примере.

// put your code here

template <typename T,
          typename U>

void copy_n(T *dest, U *src, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        dest[i] = T(src[i]);
    }
    return;
};

int main()
{

    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n(doubles, ints, 4);
    cout << doubles[3] << endl;
    return 0;
}