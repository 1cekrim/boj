#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using llong = long long;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    llong k, n;
    std::cin >> k >> n;

    std::vector<llong> data(k);
    std::priority_queue<llong, std::vector<llong>, std::greater<llong>> q;
    std::map<llong, bool> check;
    for (llong i = 0; i < k; ++i)
    {
        std::cin >> data[i];
    }
    q.emplace(1);

    llong max = std::numeric_limits<llong>::min();
    for (llong i = 0; i < n; ++i)
    {
        llong ans = q.top();
        q.pop();

        for (llong j = 0; j < k; ++j)
        {
            llong value = ans * data[j];
            if (max < value && q.size() + i + 1 > n)
            {
                continue;
            }

            if (check[value] == false)
            {
                max = std::max(max, value);
                check[value] = true;
                q.emplace(value);
            }
        }
    }

    std::cout << q.top() << '\n';

    return 0;
}