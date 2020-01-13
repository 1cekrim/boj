#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

class Map
{
 public:
    Map(int n, int m) : n(n), map(n, std::vector<int>(n, 0))
    {
        // Do nothing.
    }

    Map(const Map& map) = default;

    void show() const
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
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
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int n;
    std::vector<std::vector<int>> map;
};

int infectVirus(const Map& map,
                const std::vector<std::tuple<int, int, bool>>& able_set,
                const std::vector<int>& selected)
{
    std::vector<std::vector<bool>> check(map.n,
                                         std::vector<bool>(map.n, false));
    std::queue<std::tuple<int, int, int>> q;
    for (int i = 0; i < selected.size(); ++i)
    {
        auto [x, y, c] = able_set[selected[i]];
        q.emplace(0, x, y);
        check[y][x] = true;
    }

    constexpr int dx[] = { 0, 1, -1, 0 };
    constexpr int dy[] = { 1, 0, 0, -1 };
    int max_time = -1;
    while (!q.empty())
    {
        auto [time, x, y] = q.front();
        max_time = std::max(max_time, time);
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (map.checkBoundary(nx, ny) && map.get(nx, ny) != 1 &&
                !check[ny][nx])
            {
                check[ny][nx] = true;
                q.emplace(time + 1, nx, ny);
            }
        }
    }

    for (int i = 0; i < map.n; ++i)
    {
        for (int j = 0; j < map.n; ++j)
        {
            if (!check[i][j] && map.get(j, i) != 1)
            {
                return std::numeric_limits<int>::max();
            }
        }
    }

    return max_time;
}

int select(const Map& map, std::vector<std::tuple<int, int, bool>>& able_set,
           std::vector<int>& selected, int cond, int last)
{
    if (selected.size() == cond)
    {
        return infectVirus(map, able_set, selected);
    }

    int min = std::numeric_limits<int>::max();

    for (int i = last; i < able_set.size(); ++i)
    {
        if (!std::get<2>(able_set[i]))
        {
            std::get<2>(able_set[i]) = true;
            selected.push_back(i);
            min = std::min(min, select(map, able_set, selected, cond, i));
            std::get<2>(able_set[i]) = false;
            selected.pop_back();
        }
    }

    if (min == std::numeric_limits<int>::max())
    {
        return std::numeric_limits<int>::max();
    }

    return min;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    Map map(n, n);
    bool flag = true;
    std::vector<std::tuple<int, int, bool>> able_set;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int a;
            std::cin >> a;
            map.set(j, i, a);
            if (a == 2)
            {
                able_set.emplace_back(j, i, false);
            }
            if (a != 1)
            {
                flag = false;
            }
        }
    }

    if (flag)
    {
        std::cout << "0\n";
    }

    std::vector<int> selected;
    selected.reserve(m);
    if (int result = select(map, able_set, selected, m, 0);
        result == std::numeric_limits<int>::max())
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << result << '\n';
    }

    return 0;
}