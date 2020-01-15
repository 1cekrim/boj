#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int n;
std::vector<int> columns;

int dfs(int col)
{
    int ans{};
    if (col == n)
    {
        return 1;
    }
    for (int i = 0; i < n; ++i)
    {
        bool flag = false;
        for (int j = 0; j < col; ++j)
        {
            if (columns[j] == i)
            {
                flag = true;
                break;
            }
            if (std::abs(columns[j] - i) == std::abs(col - j))
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        columns[col] = i;
        ans += dfs(col + 1);
    }
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;

    columns.resize(n);

    std::cout << dfs(0) << '\n';

    return 0;
}