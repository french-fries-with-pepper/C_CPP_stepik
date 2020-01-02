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

int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    int **res = create_array2d(cols, rows);

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            res[i][j] = m[j][i];
        }
    }

    return res;
}

int main()
{
    //int m2d[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int **m2d = create_array2d(2, 3);
    m2d[0][0] = 1;
    m2d[0][1] = 2;
    m2d[0][2] = 3;

    m2d[1][0] = 4;
    m2d[1][1] = 5;
    m2d[1][2] = 6;

    int **m2d_new = transpose(m2d, 2, 3);

    print_array2d(m2d, 2, 3);
    print_array2d(m2d_new, 3, 2);
    return 0;
}