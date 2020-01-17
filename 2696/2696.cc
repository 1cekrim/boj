#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int m;
        std::cin >> m;
        std::cout << (m / 2 + 1) << '\n';

        std::priority_queue<int> maxHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int cnt{};
        for (int j = 0; j < m; ++j)
        {
            int a;
            std::cin >> a;

            if (maxHeap.size() <= minHeap.size())
            {
                maxHeap.push(a);
            }
            else
            {
                minHeap.push(a);
            }

            if (!maxHeap.empty() && !minHeap.empty() &&
                maxHeap.top() > minHeap.top())
            {
                int min = minHeap.top();
                int max = maxHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(min);
                minHeap.push(max);
            }
            if (!(j % 2))
            {
                std::cout << maxHeap.top() << ' ';
                if (!(++cnt % 10))
                {
                    std::cout << '\n';
                }
            }
        }
        std::cout << '\n';
    }

    return 0;
}