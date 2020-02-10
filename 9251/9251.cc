#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int solve(const std::string_view& a, const std::string_view& b, int i, int j)
{
    static std::vector<std::vector<int>> memo(
        a.size() + 1, std::vector<int>(b.size() + 1, -1));

    if (i == a.size() || j == b.size())
    {
        return 0;
    }
    if (a[i] == b[j])
    {
        return solve(a, b, i + 1, j + 1) + 1;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    return memo[i][j] = std::max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string a, b;
    std::cin >> a >> b;

    std::cout << solve(a, b, 0, 0) << '\n';

    return 0;
}