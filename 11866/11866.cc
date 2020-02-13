#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int k, n;
    std::cin >> n >> k;

    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.emplace(i);
    }

    std::cout << '<';
    while (!q.empty())
    {
        for (int i = 0; i < k - 1; ++i)
        {
            int a = q.front();
            q.pop();
            q.emplace(a);
        }

        std::cout << q.front();
        q.pop();

        if (!q.empty())
        {
            std::cout << ", ";
        }
    }
    std::cout << ">\n";

    return 0;
}