#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, max = std::numeric_limits<int>::min();
    std::cin >> n >> m;

    std::vector<std::string> map(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> map[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 'W')
            {
                continue;
            }

            std::queue<std::tuple<int, int, int>> q;
            std::vector<std::vector<int>> check(n, std::vector<int>(m, false));

            q.emplace(j, i, 0);

            while (!q.empty())
            {
                auto [x, y, cost] = q.front();
                q.pop();

                constexpr int dx[] = { 0, -1, 1, 0 };
                constexpr int dy[] = { -1, 0, 0, 1 };

                for (int k = 0; k < 4; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        !check[ny][nx] && map[ny][nx] == 'L')
                    {
                        max = std::max(max, cost + 1);
                        q.emplace(nx, ny, cost + 1);
                        check[ny][nx] = true;
                    }
                }
            }
        }
    }

    std::cout << max << '\n';
    return 0;
}