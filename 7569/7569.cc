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

    int m, n, h;
    std::cin >> m >> n >> h;

    std::vector<std::vector<std::vector<int>>> map(
        h, std::vector<std::vector<int>>(n, std::vector<int>(m, false)));
    std::vector<std::vector<std::vector<bool>>> check(
        h, std::vector<std::vector<bool>>(n, std::vector<bool>(m, false)));
    std::queue<std::tuple<int, int, int, int>> q;

    int riped{}, unriped{}, empty{};
    for (int k = 0; k < h; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cin >> map[k][i][j];
                switch (map[k][i][j])
                {
                    case 1:
                        ++riped;
                        q.emplace(j, i, k, 0);
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
    }

    if (riped + empty == n * m * h)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    int cnt{}, max = std::numeric_limits<int>::min();
    while (!q.empty())
    {
        auto [x, y, z, day] = q.front();
        max = std::max(max, day);
        q.pop();

        constexpr int dx[] = { 0, 0, 0, 0, 1, -1 };
        constexpr int dy[] = { 0, 0, 1, -1, 0, 0 };
        constexpr int dz[] = { 1, -1, 0, 0, 0, 0 };
        for (int i = 0; i < 6; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && nz >= 0 && nz < h &&
                map[nz][ny][nx] == 0 && !check[nz][ny][nx])
            {
                map[nz][ny][nx] = 1;
                check[nz][ny][nx] = true;
                q.emplace(nx, ny, nz, day + 1);
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