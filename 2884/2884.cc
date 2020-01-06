#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int h, m;
    std::cin >> h >> m;

    m -= 45;
    if (m < 0)
    {
        --h;
        m += 60;
    }

    if (h < 0)
    {
        h = 23;
    }

    std::cout << h << ' ' << m << '\n';
    return 0;
}