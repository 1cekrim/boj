#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct comp
{
    bool operator()(const std::pair<int, int>& lhs,
                    const std::pair<int, int>& rhs)
    {
        return lhs.second > rhs.second;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    const int INF = std::numeric_limits<int>::max();

    int v, e, start;

    std::cin >> v >> e >> start;

    std::vector<std::vector<std::pair<int, int>>> graph(v);
    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
    }

    std::vector<int> distance(v, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        comp>
        pq;

    distance[start - 1] = 0;
    pq.emplace(start - 1, 0);

    while (!pq.empty())
    {
        auto [base, cost] = pq.top();
        pq.pop();

        if (cost > distance[base])
        {
            continue;
        }

        for (std::size_t i = 0; i < graph[base].size(); ++i)
        {
            auto [neighbor, neighborCost] = graph[base][i];
            neighborCost += cost;

            if (neighborCost < distance[neighbor])
            {
                distance[neighbor] = neighborCost;
                pq.emplace(neighbor, neighborCost);
            }
        }
    }

    for (int d : distance)
    {
        if (d == INF)
        {
            std::cout << "INF\n";
        }
        else
        {
            std::cout << d << '\n';
        }
    }

    return 0;
}