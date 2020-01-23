#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ullong = unsigned long long;

constexpr ullong p = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    ullong a, x, result = 1;
    std::cin >> a >> x;

    a %= p;

    while (x)
    {
        if (x & 1)
        {
            result *= a;
            result %= p;
        }
        a *= a;
        a %= p;
        x >>= 1;
    }

    std::cout << result << '\n';

    return 0;
}