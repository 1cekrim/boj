#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using Map = std::vector<std::string>;

std::string divide(const Map& map, int lx, int ly, int rx, int ry)
{
    bool flag_white = true, flag_blue = true;
    for (int i = ly; i < ry; ++i)
    {
        for (int j = lx; j < rx; ++j)
        {
            if (map[i][j] != '0')
            {
                flag_white = false;
            }
            else if (map[i][j] != '1')
            {
                flag_blue = false;
            }
        }
    }
    if (flag_white)
    {
        return "0";
    }
    if (flag_blue)
    {
        return "1";
    }

    std::string s;
    s += divide(map, lx, ly, (lx + rx) / 2, (ly + ry) / 2);
    s += divide(map, (lx + rx) / 2, ly, rx, (ly + ry) / 2);
    s += divide(map, lx, (ly + ry) / 2, (lx + rx) / 2, ry);
    s += divide(map, (lx + rx) / 2, (ly + ry) / 2, rx, ry);
    return "(" + s + ")";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    Map map(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> map[i];
    }

    std::cout << divide(map, 0, 0, n, n) << '\n';

    return 0;
}