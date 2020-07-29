#include<iostream>

template<class F>
int * find_if(int * p, int * q, F f)
{
    for ( ; p != q; ++p )
        if (f(*p))
            return p;
    return q;
}

auto gen_finder = [](int * l,int  * r){
    return [l,r](int x){
        bool res = false;
        int * left = l;
        int * right = r;
        for(;left!=right;++left){
            if(*left==x) return true;
        }
        return res;
    };
}; 


int main(){

    int primes[5] = {2,3,5,7,11};
    int m[10] = {0,0,1,1,4,6,7,8,9,10};

    int * first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));
    std::cout << *first_prime << std::endl;
    return 0;
}