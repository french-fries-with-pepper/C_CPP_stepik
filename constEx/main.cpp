#include<iostream>

// определение структуры Point уже подключено
struct Point
{
    constexpr Point(double x, double y) 
        : x(x), y(y) 
    {}

    double x = 0;
    double y = 0;
};


// сложение
constexpr Point operator+(Point const &lh,  Point const &rh)
{
    return Point(lh.x+rh.x,lh.y+rh.y);
}

// вычитание
constexpr Point operator-(Point const &lh,Point const &rh)
{
    return Point(lh.x-rh.x,lh.y-rh.y);
}

// скалярное произведение
constexpr double operator*(Point const &lh,Point const &rh)
{
    return lh.x*rh.x+lh.y*rh.y;
}
template<class F>
void for_each_int(int * p, int * q, F f)
{
    for ( ; p != q; ++p )
        f(*p);
}

int main(){

    constexpr size_t size = static_cast<size_t>(Point(2,4) * Point(4,3));

    //auto square_fun = [](auto x){return x*x;};
    int m[10] = {1,2,3,4,5,6,7,8,9,10};

    auto square_fun = [](int & x){x * x;};
    int tmp = 5;
    for_each_int(m, m + 10, square_fun); 
    std::cout << m[8] << std::endl;

    

    return 0;
}