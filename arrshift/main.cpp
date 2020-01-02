#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
    return;
}

void shiftByOne(int a[], int size)
{
    int last = a[0];
    for (int i = 0; i < size - 1; i++)
    {
        swap(&a[i], &a[i + 1]);
    }
    a[size - 1] = last;
    return;
}

void printArr(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return;
}

void rotate(int a[], unsigned size, int shift)
{
    int realShift = shift % size;
    if (realShift == 0)
        return;

    for (int i = 0; i < realShift; i++)
    {
        shiftByOne(a, size);
    }

    return;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int shift = 2;

    //rotate(arr, size, shift);
    //swap(&size, &shift);
    printArr(arr, size);

    rotate(arr, size, shift);

    printArr(arr, size);

    return 0;
}