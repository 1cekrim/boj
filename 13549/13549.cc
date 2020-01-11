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

    std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>,
                        std::greater<std::tuple<int, int>>>
        q;
    std::vector<bool> check(100001, false);

    q.emplace(0, n);
    check[n] = true;

    while (!q.empty())
    {
        auto [cnt, pos] = q.top();
        q.pop();

        if (pos == k)
        {
            std::cout << cnt << '\n';
            return 0;
        }

        if (int npos = pos - 1; checkBoundary(npos) && !check[npos])
        {
            check[pos] = true;
            q.emplace(cnt + 1, npos);
        }

        if (int npos = pos + 1; checkBoundary(npos) && !check[npos])
        {
            check[pos] = true;
            q.emplace(cnt + 1, npos);
        }

        if (int npos = pos * 2; checkBoundary(npos) && !check[npos])
        {
            check[pos] = true;
            q.emplace(cnt, npos);
        }
    }

    return 0;
}