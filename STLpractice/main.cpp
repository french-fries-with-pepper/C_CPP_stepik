#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    vector<int> v;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int pos;
    cin >> pos;
    v.erase(v.begin()+pos-1);
    int s,f;
    cin >> s >> f;
    v.erase(v.begin()+s-1,v.begin()+f-1);
    n = v.size();

    for (size_t i = 0; i < n; i++)
    {
        /* code */
        cout << v[i] << " ";
    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
