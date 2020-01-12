#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using Map = std::vector<std::vector<int>>;

int white, blue;

void divide(const Map& map, int lx, int ly, int rx, int ry)
{
    bool flag_white = true, flag_blue = true;
    for (int i = ly; i < ry; ++i)
    {
        for (int j = lx; j < rx; ++j)
        {
            if (map[i][j] != 0)
            {
                flag_white = false;
            }
            else if (map[i][j] != 1)
            {
                flag_blue = false;
            }
        }
    }
    if (flag_white)
    {
        ++white;
        return;
    }
    if (flag_blue)
    {
        ++blue;
        return;
    }

    divide(map, lx, ly, (lx + rx) / 2, (ly + ry) / 2);
    divide(map, (lx + rx) / 2, (ly + ry) / 2, rx, ry);
    divide(map, (lx + rx) / 2, ly, rx, (ly + ry) / 2);
    divide(map, lx, (ly + ry) / 2, (lx + rx) / 2, ry);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    Map map(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int a;
            std::cin >> a;
            map[i][j] = a;
        }
    }

    divide(map, 0, 0, n, n);

    std::cout << white << '\n' << blue << '\n';

    return 0;
}