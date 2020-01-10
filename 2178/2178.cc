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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> map(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> map[i];
    }

    std::queue<std::tuple<int, int, int>> q;
    std::vector<std::vector<bool>> check(n, std::vector<bool>(m, false));

    q.emplace(0, 0, 1);
    check[0][0] = true;

    while (!q.empty())
    {
        auto [x, y, cost] = q.front();
        q.pop();

        if (x == m - 1 && y == n - 1)
        {
            std::cout << cost << '\n';
            break;
        }

        constexpr int dx[] = { 0, -1, 0, 1 };
        constexpr int dy[] = { 1, 0, -1, 0 };
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[ny][nx] == '1' &&
                !check[ny][nx])
            {
                q.emplace(nx, ny, cost + 1);
                check[ny][nx] = true;
            }
        }
    }

    return 0;
}