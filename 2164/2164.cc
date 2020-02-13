#include <deque>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::deque<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.emplace_back(i);
    }

    while (q.size() != 1)
    {
        q.pop_front();

        int a = q.front();
        q.pop_front();
        q.emplace_back(a);
    }

    std::cout << q.front() << '\n';

    return 0;
}