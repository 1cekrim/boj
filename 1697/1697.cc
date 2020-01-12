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

    q.emplace(n, 0);
    check[n] = true;

    while (!q.empty())
    {
        auto [pos, cnt] = q.front();
        q.pop();

        if (pos == k)
        {
            std::cout << cnt << '\n';
            return 0;
        }

        if (int npos = pos - 1; checkBoundary(npos) && !check[npos])
        {
            check[npos] = true;
            q.emplace(npos, cnt + 1);
        }

        if (int npos = pos + 1; checkBoundary(npos) && !check[npos])
        {
            check[npos] = true;
            q.emplace(npos, cnt + 1);
        }

        if (int npos = pos * 2; checkBoundary(npos) && !check[npos])
        {
            check[npos] = true;
            q.emplace(npos, cnt + 1);
        }
    }

    return 0;
}