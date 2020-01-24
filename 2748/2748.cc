#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ull = unsigned long long;

std::vector<ull> memo;

ull fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo[n])
    {
        return memo[n];
    }
    return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    memo.resize(n + 1, 0);

    std::cout << fibo(n) << '\n';

    return 0;
}