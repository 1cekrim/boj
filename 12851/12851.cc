#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

bool checkBoundary(int pos)
{
    return pos >= 0 && pos <= 100000;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::queue<std::tuple<int, int>> q;
    std::vector<bool> check(100001, false);

    int min = std::numeric_limits<int>::max();
    int min_cnt{};

    q.emplace(n, 0);
    check[n] = true;

    while (!q.empty())
    {
        auto [pos, cnt] = q.front();
        q.pop();
        check[pos] = true;

        if (pos == k)
        {
            if (min == cnt)
            {
                ++min_cnt;
            }
            else if (min > cnt)
            {
                min = cnt;
                min_cnt = 1;
            }
        }

        if (int npos = pos - 1; checkBoundary(npos) && !check[npos])
        {
            q.emplace(npos, cnt + 1);
        }

        if (int npos = pos + 1; checkBoundary(npos) && !check[npos])
        {
            q.emplace(npos, cnt + 1);
        }

        if (int npos = pos * 2; checkBoundary(npos) && !check[npos])
        {
            q.emplace(npos, cnt + 1);
        }
    }

    std::cout << min << '\n' << min_cnt << '\n';

    return 0;
}