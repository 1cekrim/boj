#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using llong = long long;

llong a, b, c;

llong divide_and_conquer(llong n)
{
    if (n == 0)
    {
        return 1;
    }

    llong temp = divide_and_conquer(n / 2);
    temp *= temp;
    temp %= c;

    if (n % 2)
    {
        return temp * a % c;
    }

    return temp;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a >> b >> c;

    std::cout << divide_and_conquer(b) << '\n';

    return 0;
}