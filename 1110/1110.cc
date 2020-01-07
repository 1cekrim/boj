#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, cnt{};
    std::cin >> n;

    int now = n;

    do
    {
        if (now < 10)
        {
            now = now + now * 10;
            ++cnt;
            continue;
        }

        now = (now % 10) * 10 + (now % 10 + now / 10) % 10;
        ++cnt;
    } while (now != n);

    std::cout << cnt << '\n';

    return 0;
}