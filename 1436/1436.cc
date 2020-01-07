#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int cnt{}, ans{};
    while (cnt < n)
    {
        int a = ++ans;
        while (a)
        {
            if (a % 1000 == 666)
            {
                ++cnt;
                break;
            }
            a /= 10;
        }
    }

    std::cout << ans << '\n';

    return 0;
}