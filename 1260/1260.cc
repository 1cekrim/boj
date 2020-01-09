#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, v;
    std::cin >> n >> m >> v;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int start, end;
        std::cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for (int i = 1; i <= n; ++i)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }

    std::stack<int> s;
    std::vector<bool> check(n + 1, false);
    check[v] = true;
    std::cout << v << ' ';
    s.push(v);

    while (!s.empty())
    {
        int now = s.top();
        s.pop();

        for (int vertex : graph[now])
        {
            if (!check[vertex])
            {
                check[vertex] = true;
                std::cout << vertex << ' ';
                s.push(now);
                s.push(vertex);
                break;
            }
        }
    }
    std::cout << '\n';

    std::queue<int> q;
    std::fill(check.begin(), check.end(), false);
    check[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int now = q.front();
        check[now] = true;
        std::cout << now << ' ';
        q.pop();

        for (int vertex : graph[now])
        {
            if (!check[vertex])
            {
                check[vertex] = true;
                q.push(vertex);
            }
        }
    }
    std::cout << '\n';

    return 0;
}