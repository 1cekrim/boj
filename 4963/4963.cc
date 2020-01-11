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

    while (true)
    {
        int w, h;
        std::cin >> w >> h;
        if (w == 0 && h == 0)
        {
            break;
        }

        std::vector<std::vector<int>> map(h, std::vector<int>(w));
        std::vector<std::vector<bool>> check(h, std::vector<bool>(w, false));

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                std::cin >> map[i][j];
            }
        }

        int cnt{};
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (check[i][j] || map[i][j] == 0)
                {
                    continue;
                }

                std::queue<std::tuple<int, int>> q;

                q.emplace(j, i);
                check[i][j] = true;
                ++cnt;

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    constexpr int dx[] = { 0, 1, 1, 1, -1, -1, -1, 0 };
                    constexpr int dy[] = { 1, -1, 0, 1, -1, 0, 1, -1 };

                    for (int k = 0; k < 8; ++k)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && ny >= 0 && nx < w && ny < h &&
                            !check[ny][nx] && map[ny][nx] == 1)
                        {
                            check[ny][nx] = 1;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }

        std::cout << cnt << '\n';
    }

    return 0;
}