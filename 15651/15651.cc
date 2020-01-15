#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<bool> check;
std::vector<int> ans;
int n, m;

void solve(const std::vector<int>& ans)
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

    for (int i = 1; i <= n; ++i)
    {
        copy.push_back(i);
        solve(copy);
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
    solve(ans);

    return 0;
}