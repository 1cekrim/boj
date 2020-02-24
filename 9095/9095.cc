#include <iostream>
#include <vector>

int solve(int a)
{
    static int memo[12] = { 0, 1, 2, 4 };

    if (memo[a])
    {
        return memo[a];
    }

    return memo[a] = solve(a - 1) + solve(a - 2) + solve(a - 3);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    while (n--)
    {
        int a;
        std::cin >> a;

        std::cout << solve(a) << '\n';
    }

    return 0;
}