#include <iostream>

using namespace std;

int myLogFunc(int a){
    for(int i = 0;;i++){
        int answ = 1 << i;
        if (answ>a)
        {
            /* code */
            return i -1;
        }
        
    }
}

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        /* code */
        int a = 0;

        cin >> a;


        cout << myLogFunc(a) << "\n";
    }
    
    return 0;
}