#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

class Map
{
 public:
    Map(int n, int m) : n(n), m(m), map(n, std::vector<int>(m, 0))
    {
        // Do nothing.
    }

    Map(const Map& map) = default;

    void show() const
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cout << map[i][j];
            }
            std::cout << '\n';
        }
    }

    void set(int x, int y, int value)
    {
        map[y][x] = value;
    }

    int get(int x, int y) const
    {
        return map[y][x];
    }

    bool checkBoundary(int x, int y) const
    {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int n, m;
    std::vector<std::vector<int>> map;
};

int getLeft(int dir)
{
    --dir;
    if (dir < 0)
    {
        dir = 3;
    }
    return dir;
}

int getRight(int dir)
{
    ++dir;
    if (dir > 3)
    {
        dir = 0;
    }
    return dir;
}

int solve(const Map& map, int x, int y, int dir)
{
    Map copy(map);

    std::stack<std::tuple<int, int, int>> s;
    s.emplace(x, y, dir);

    constexpr int dx[] = { 0, 1, 0, -1 };
    constexpr int dy[] = { -1, 0, 1, 0 };

    int cnt{};
    while (!s.empty())
    {
        auto [x, y, dir] = s.top();
        s.pop();

        if (copy.get(x, y) == 0)
        {
            ++cnt;
            copy.set(x, y, 2);
        }

        bool flag = false;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[(dir - i + 3) % 4];
            int ny = y + dy[(dir - i + 3) % 4];
            if (copy.checkBoundary(nx, ny) && copy.get(nx, ny) == 0)
            {
                flag = true;
                s.emplace(nx, ny, (dir - i + 3) % 4);
                break;
            }
        }

        if (!flag)
        {
            int nx = x - dx[dir];
            int ny = y - dy[dir];
            if (copy.checkBoundary(nx, ny) && copy.get(nx, ny) == 1)
            {
                break;
            }
            else
            {
                s.emplace(nx, ny, dir);
            }
        }
    }

    return cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    int x, y, dir;
    std::cin >> x >> y >> dir;

    Map map(n, m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int a;
            std::cin >> a;

            map.set(j, i, a);
        }
    }

    std::cout << solve(map, y, x, dir) << '\n';

    return 0;
}