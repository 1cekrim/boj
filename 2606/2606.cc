#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<bool> check(n + 1, false);
    std::queue<int> q;
    q.push(1);
    check[1] = true;

    int cnt{};
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        ++cnt;

        for (int vertex : graph[now])
        {
            if (!check[vertex])
            {
                check[vertex] = true;
                q.push(vertex);
            }
        }
    }

    std::cout << cnt - 1 << '\n';

    return 0;
}