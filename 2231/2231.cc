#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, ans{};
    std::cin >> n;

    for (int i = 1; i < n; ++i)
    {
        int a = i, s = i;

        while (a)
        {
            s += a % 10;
            a /= 10;
        }

        if (s == n)
        {
            ans = i;
            break;
        }
    }

    std::cout << ans << '\n';

    return 0;
}