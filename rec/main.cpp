#include <iostream>

using namespace std;

void strange (int a){
    if (a==0){
        return ;
    } else {
                int b=0;
        cin >> b;
         strange(b);

        cout << a << " ";
        return ;
    }
}

int main(){


    int a =0;
    cin >> a;

    strange(a);
        cout << '\n';

    return 0;
}