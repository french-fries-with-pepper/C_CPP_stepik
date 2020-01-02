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
    int min = m[0][0];

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

    int * tmpRow[] = {m[0]};

    m[0]=m[minRow];
    m[minRow] = *tmpRow;
}

int main()
{
    int ** arr1 = create_array2d(3,3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr1[i][j] = i+j;
        }
    }

    arr1[2][2] = -3;

    print_array2d(arr1,3,3);
    swap_min(arr1,3,3);
    print_array2d(arr1,3,3);

    

    return 0;
}