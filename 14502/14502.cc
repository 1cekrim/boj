#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
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

int infectVirus(const Map& map)
{
    Map copy(map);

    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < copy.n; ++i)
    {
        for (int j = 0; j < copy.m; ++j)
        {
            if (copy.get(j, i) == 2)
            {
                q.emplace(j, i);
            }
        }
    }

    constexpr int dx[] = { 0, 1, -1, 0 };
    constexpr int dy[] = { 1, 0, 0, -1 };
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (copy.checkBoundary(nx, ny) && copy.get(nx, ny) == 0)
            {
                copy.set(nx, ny, 2);
                q.emplace(nx, ny);
            }
        }
    }

    int cnt{};
    for (int i = 0; i < copy.n; ++i)
    {
        for (int j = 0; j < copy.m; ++j)
        {
            if (copy.get(j, i) == 0)
            {
                ++cnt;
            }
        }
    }

    return cnt;
}

int solve(const Map& map, int count)
{
    if (count == 3)
    {
        return infectVirus(map);
    }

    Map copy(map);
    int max = std::numeric_limits<int>::min();

    for (int i = 0; i < copy.n; ++i)
    {
        for (int j = 0; j < copy.m; ++j)
        {
            if (copy.get(j, i) == 0)
            {
                copy.set(j, i, 1);
                max = std::max(max, solve(copy, count + 1));
                copy.set(j, i, 0);
            }
        }
    }

    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

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

    std::cout << solve(map, 0) << '\n';

    return 0;
}