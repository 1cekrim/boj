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

    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int i = 0; i < n; ++i)
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
            int min = minHeap.top(), max = maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            minHeap.push(max);
            maxHeap.push(min);
        }

        std::cout << maxHeap.top() << '\n';
    }

    return 0;
}