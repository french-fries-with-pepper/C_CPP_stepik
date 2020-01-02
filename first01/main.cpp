#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;
    int d = 0;

   cin >> a >> b >> c;

    d = b*b - 4*a*c;

    if (d<0)
    {
        cout << "No real roots\n";
        return 0;
    } else
    {
        double x1, x2;
        x1 = ( - b + sqrt(d)) / (2*a);
        x2 = ( - b- sqrt(d)) / (2*a);
        cout << x1<<" "<<x2<<"\n";
        return 0;
    }
    
    


    return 0;
}