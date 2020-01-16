#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    int start, end;
    std::cin >> start >> end;

    std::vector<bool> check(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        q;
    q.emplace(0, start);
    check[start] = true;

    while (!q.empty())
    {
        auto [score, source] = q.top();
        check[source] = true;
        q.pop();

        if (source == end)
        {
            std::cout << score << '\n';
            break;
        }

        for (auto& node : graph[source])
        {
            auto [target, cost] = node;
            if (!check[target])
            {
                q.emplace(score + cost, target);
            }
        }
    }

    return 0;
}