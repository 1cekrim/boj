#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a;
    std::cin >> a;

    static int dp[1000001];

    for (int i = 2; i <= a; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if (!(i % 2))
        {
            dp[i] = std::min(dp[i], dp[i / 2] + 1);
        }
        if (!(i % 3))
        {
            dp[i] = std::min(dp[i], dp[i / 3] + 1);
        }
    }

    std::cout << dp[a] << '\n';

    return 0;
}