#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::priority_queue<int> q;
    while (n)
    {
        q.emplace(n % 10);
        n /= 10;
    }

    while (!q.empty())
    {
        std::cout << q.top();
        q.pop();
    }
    std::cout << '\n';

    return 0;
}