#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int m, n, k;
        std::cin >> m >> n >> k;

        std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
        std::vector<std::vector<bool>> check(n, std::vector<bool>(m, false));

        for (int j = 0; j < k; ++j)
        {
            int x, y;
            std::cin >> x >> y;

            map[y][x] = 1;
        }

        int ans{};
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < m; ++x)
            {
                if (map[y][x] != 1 || check[y][x])
                {
                    continue;
                }

                ++ans;

                std::queue<std::pair<int, int>> q;
                q.emplace(x, y);
                check[y][x] = true;

                constexpr int dx[] = { -1, 0, 1, 0 };
                constexpr int dy[] = { 0, -1, 0, 1 };
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int p = 0; p < 4; ++p)
                    {
                        int nx = x + dx[p];
                        int ny = y + dy[p];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                            map[ny][nx] == 1 && !check[ny][nx])
                        {
                            q.emplace(nx, ny);
                            check[ny][nx] = true;
                        }
                    }
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}