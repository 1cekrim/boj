#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> map(n, std::vector<int>(m));
    std::vector<std::vector<bool>> check(n, std::vector<bool>(m, false));
    std::queue<std::tuple<int, int, int>> q;

    int riped{}, unriped{}, empty{};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
            switch (map[i][j])
            {
                case 1:
                    ++riped;
                    q.emplace(j, i, 0);
                    break;
                case -1:
                    ++empty;
                    break;
                default:
                    ++unriped;
                    break;
            }
        }
    }

    if (riped + empty == n * m)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    int cnt{}, max = std::numeric_limits<int>::min();
    while (!q.empty())
    {
        auto [x, y, day] = q.front();
        max = std::max(max, day);
        q.pop();

        constexpr int dx[] = { 0, 1, 0, -1 };
        constexpr int dy[] = { 1, 0, -1, 0 };
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[ny][nx] == 0 &&
                !check[ny][nx])
            {
                map[ny][nx] = 1;
                check[ny][nx] = true;
                q.emplace(nx, ny, day + 1);
                ++cnt;
            }
        }
    }

    if (cnt != unriped)
    {
        std::cout << -1 << '\n';
        return 0;
    }

    std::cout << max << '\n';

    return 0;
}