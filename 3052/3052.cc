#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<bool> check(42, false);
    int cnt{};
    for (int i = 0; i < 10; ++i)
    {
        int a;
        std::cin >> a;
        if (!check[a % 42])
        {
            check[a % 42] = true;
            ++cnt;
        }
    }

    std::cout << cnt << '\n';

    return 0;
}