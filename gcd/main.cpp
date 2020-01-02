#include <iostream>

using namespace std;


unsigned gcd(unsigned a, unsigned b)
{
    if(a<b){
        /* swap(a,b); */
        unsigned tmp = a;
        a = b;
        b = tmp;
    }

    if (b==0)
    {
        return a;
    }else{
       return gcd(b,a % b);
    }
    
}

int main(){

    unsigned a =0;
    unsigned b =0;

    cin >> a >> b;

    cout << gcd(a,b) << "\n";




    return 0;
}
