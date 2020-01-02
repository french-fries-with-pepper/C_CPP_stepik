#include <iostream>
using namespace std;

int main()
{
    // put your code here
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        cout << a + b << "\n";
    }

    return 0;
}