#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, i;
    std::cin >> a;
    std::vector<int> dp(a + 1, std::numeric_limits<int>::max());

    for (i = 0; i < a; ++i)
    {
        int b;
        std::cin >> b;
        (*std::lower_bound(dp.begin(), dp.end(), b)) = b;
    }

    for (i = 0; dp[i] != std::numeric_limits<int>::max(); ++i)
        ;
    std::cout << i;
    return 0;
}