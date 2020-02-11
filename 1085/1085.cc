#include <algorithm>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    std::cout << std::min({ x, y, w - x, h - y });

    return 0;
}