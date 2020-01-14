#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

int r, c, max;
std::vector<std::string> map;
std::vector<bool> check(26, false);

void dfs(int x, int y, int cnt)
{
    constexpr int dx[] = { 0, 1, -1, 0 };
    constexpr int dy[] = { 1, 0, 0, -1 };

    max = std::max(max, cnt);

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (ny >= 0 && nx >= 0 && ny < r && nx < c && !check[map[ny][nx] - 'A'])
        {
            check[map[ny][nx] - 'A'] = true;
            dfs(nx, ny, cnt + 1);
            check[map[ny][nx] - 'A'] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> r >> c;

    for (int i = 0; i < r; ++i)
    {
        std::string s;
        std::cin >> s;
        map.emplace_back(s);
    }

    check[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    std::cout << max << '\n';

    return 0;
}