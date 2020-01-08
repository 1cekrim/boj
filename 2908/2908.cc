#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;

    auto func = [](int n) {
        int r{};
        while (n)
        {
            r = r * 10 + n % 10;
            n /= 10;
        }
        return r;
    };

    int ra = func(a), rb = func(b);

    std::cout << (ra > rb ? ra : rb) << '\n';

    return 0;
}