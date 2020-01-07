#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> data(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> data[i];
    }

    int ans = std::numeric_limits<int>::min();

    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (int sum = data[i] + data[j] + data[k]; sum <= m && sum > ans)
                {
                    ans = sum;
                }
            }
        }
    }

    std::cout << ans;

    return 0;
}