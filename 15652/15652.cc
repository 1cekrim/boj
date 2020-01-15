#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<bool> check;
std::vector<int> ans;
int n, m;

void solve(const std::vector<int>& ans, int idx)
{
    if (ans.size() == m)
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    std::vector<int> copy(ans);

    for (int i = idx; i <= n; ++i)
    {
        copy.push_back(i);
        solve(copy, i);
        copy.pop_back();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m;

    check.resize(n + 1, false);

    std::vector<int> ans;
    solve(ans, 1);

    return 0;
}