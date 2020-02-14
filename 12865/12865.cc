#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int solve(const std::vector<std::tuple<int, int>> data, int idx, int cap)
{
    static std::vector<std::vector<int>> memo(idx + 1,
                                              std::vector<int>(cap + 1, 0));

    if (!(idx && cap))
    {
        return 0;
    }

    if (memo[idx][cap])
    {
        return memo[idx][cap];
    }

    auto [weight, value] = data[idx];

    if (weight > cap)
    {
        return memo[idx][cap] = solve(data, idx - 1, cap);
    }

    return memo[idx][cap] =
               std::max(solve(data, idx - 1, cap),
                        solve(data, idx - 1, cap - weight) + value);
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<std::tuple<int, int>> data(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        data[i] = { a, b };
    }

    std::cout << solve(data, n, k) << '\n';
}