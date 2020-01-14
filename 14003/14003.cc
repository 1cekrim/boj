#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    constexpr int head_idx = -1;

    int a, i, max_idx = 0, max = std::numeric_limits<int>::min();
    std::cin >> a;
    std::vector<std::tuple<int, int>> trace;
    std::vector<int> dp(a + 1, std::numeric_limits<int>::max());
    std::vector<int> parent_trace(a + 1);

    for (i = 0; i < a; ++i)
    {
        int b;
        std::cin >> b;
        int insert_pos = std::distance(
            dp.begin(), std::lower_bound(dp.begin(), dp.end(), b));
        if (insert_pos >= max)
        {
            max = insert_pos;
            max_idx = i;
        }
        dp[insert_pos] = b;
        parent_trace[insert_pos] = i;
        int parent =
            (insert_pos == 0 ? head_idx : parent_trace[insert_pos - 1]);
        trace.emplace_back(parent, b);
    }

    std::cout << max + 1 << '\n';

    std::stack<int> ans;
    int now = max_idx;
    while (now != head_idx)
    {
        auto [parent, b] = trace[now];
        ans.push(b);
        now = parent;
    }

    while (!ans.empty())
    {
        std::cout << ans.top() << ' ';
        ans.pop();
    }

    std::cout << '\n';

    return 0;
}