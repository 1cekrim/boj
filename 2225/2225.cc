#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using llong = long long;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<llong>> dp(k + 1, std::vector<llong>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int q = j; q >= 0; --q)
            {
                dp[i][j] += dp[i - 1][q];
                dp[i][j] %= 1000000000;
            }
        }
    }

    std::cout << dp[k][n] << '\n';

    return 0;
}