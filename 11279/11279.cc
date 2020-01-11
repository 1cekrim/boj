#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::less<int>> q;

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;

        if (a == 0)
        {
            if (q.empty())
            {
                std::cout << "0\n";
            }
            else
            {
                std::cout << q.top() << '\n';
                q.pop();
            }
        }
        else
        {
            q.push(a);
        }
    }
    return 0;
}