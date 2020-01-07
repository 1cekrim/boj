#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n), ans(n, 1);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            if (x[i] < x[j] && y[i] < y[j])
            {
                ++ans[i];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}