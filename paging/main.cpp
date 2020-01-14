#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream myfile("input.txt", std::ios_base::in);
    unsigned long m = 0;
    unsigned long q = 0;
    unsigned long r = 0;

    myfile >> m >> q >> r;

    cout << m << q << r;

    return 0;
}