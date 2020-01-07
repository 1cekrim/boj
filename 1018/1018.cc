#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, ans = std::numeric_limits<int>::max();
    std::cin >> n >> m;

    std::vector<std::string> board(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> board[i];
    }

    auto func = [&board](int x, int y, bool isWhite) {
        int cnt{};
        char c[2] = {isWhite ? 'W' : 'B', isWhite ? 'B' : 'W'};
        for (int i = y; i < y + 8; ++i)
        {
            for (int j = x; j < x + 8; ++j)
            {
                cnt += board[i][j] != c[(i + j) % 2];
            }
        }
        return cnt;
    };

    for (int i = 0; i + 7 < n; ++i)
    {
        for (int j = 0; j + 7 < m; ++j)
        {
            ans = std::min(ans, std::min(func(j, i, true), func(j, i, false)));
        }
    }

    std::cout << ans << '\n';

    return 0;
}