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

    int m, n;
    std::cin >> m >> n;

    std::vector<std::string> map(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> map[i];
    }

    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>>>
        q;
    std::vector<std::vector<bool>> check(n, std::vector<bool>(m, false));

    q.emplace(0, 0, 0);
    check[0][0] = true;
    while (!q.empty())
    {
        auto [cost, x, y] = q.top();
        q.pop();

        if (x == m - 1 && y == n - 1)
        {
            std::cout << cost << '\n';
            return 0;
        }

        constexpr int dx[] = { 0, 1, 0, -1 };
        constexpr int dy[] = { 1, 0, -1, 0 };
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !check[ny][nx])
            {
                if (map[ny][nx] == '0')
                {
                    q.emplace(cost, nx, ny);
                    check[ny][nx] = true;
                }
                else
                {
                    q.emplace(cost + 1, nx, ny);
                    check[ny][nx] = true;
                }
            }
        }
    }
    return 0;
}