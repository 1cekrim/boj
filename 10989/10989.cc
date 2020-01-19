#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> check(10001, 0);
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        ++check[a];
    }

    for (int i = 1; i <= 10000; ++i)
    {
        for (int j = 0; j < check[i]; ++j)
        {
            std::cout << i << '\n';
        }
    }

    return 0;
}