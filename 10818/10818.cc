#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, max = std::numeric_limits<int>::min(), min = std::numeric_limits<int>::max();
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        max = std::max(a, max);
        min = std::min(a, min);
    }

    std::cout << min << ' ' << max << '\n';

    return 0;
}