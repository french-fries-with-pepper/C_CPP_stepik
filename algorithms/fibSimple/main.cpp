#include <cassert>
#include <iostream>

class Fibonacci
{
public:
    static int get(int n)
    {
        assert(n >= 0);
        // put your code here
        if (n <= 1)
        {
            return n;
        }

        int current = 1;
        int prev = 0;
        int sum = 0;

        for (int i = 1; i < n; i++)
        {
            sum = (current + prev) % 10;
            prev = current;
            current = sum;
        }

        return current;
    }
};

int main(void)
{
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}