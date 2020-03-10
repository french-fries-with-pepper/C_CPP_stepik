#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iomanip>

struct Item
{
    int weight;
    int value;
};

double getPrice(const Item &item)
{
    return static_cast<double>(item.weight) / item.value;
}

long double getMaxValue(int capacity, std::vector<Item> items)
{
    long double res = 0.0;

    std::sort(items.begin(), items.end(), [](const Item &lhs, const Item &rhs) {
        return getPrice(lhs) < getPrice(rhs);
    });

    for (Item &item : items)
    {
        if (capacity > item.weight)
        {
            capacity -= item.weight;
            res += item.value;
        }
        else
        {
            res += item.value * (static_cast<long double>(capacity) / item.weight);
            break;
        }
    }

    return res;
}

int main()
{
    int n;
    int bagCapacity;
    std::cin >> n >> bagCapacity;

    std::vector<Item> items(n);

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> items[i].value >> items[i].weight;
    }

    double result = getMaxValue(bagCapacity, move(items));
    std::cout << std::fixed << std::setprecision(3) << result << std::endl;
    return 0;
}