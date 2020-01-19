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

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        q.emplace(a);
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << q.top() << '\n';
        q.pop();
    }

    return 0;
}