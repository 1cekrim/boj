#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool hansu(int n)
{
    if (n < 100)
    {
        return true;
    }

    std::vector<int> digit;
    while (n)
    {
        digit.push_back(n % 10);
        n /= 10;
    }

    int d = digit[1] - digit[0];

    for (int i = 1; i < digit.size() - 1; ++i)
    {
        if (d != digit[i + 1] - digit[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int cnt{};
    for (int i = 1; i <= n; ++i)
    {
        if (hansu(i))
        {
            ++cnt;
        }
    }

    std::cout << cnt << '\n';

    return 0;
}