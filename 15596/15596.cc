#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

long long sum(std::vector<int> &a)
{
    long long sum{};
    for (int num : a)
    {
        sum += num;
    }
    return sum;
}