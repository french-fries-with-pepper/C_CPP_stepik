#include <iostream>
using namespace std;

int **create_array2d(size_t a, size_t b)
{
    int **m = new int *[a];
    m[0] = new int[a * b];
    for (size_t i = 1; i != a; ++i)
        m[i] = m[i - 1] + b;
    return m;
}
void free_array2d(int **m, size_t a, size_t b)
{
    delete[] m[0];
    delete[] m;
}

void print_array2d(int **m, unsigned rows, unsigned cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int minRow = 0;
    int min = 1 << 32;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (m[i][j] < min)
            {
                min = m[i][j];
                minRow = i;
            }
        }
    }
}

int main()
{

    return 0;
}