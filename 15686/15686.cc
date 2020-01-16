#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int n, m;

std::vector<std::tuple<int, int>> house;
std::vector<std::tuple<int, int>> chicken;
std::vector<bool> check;

int solve(const std::vector<int>& selected, int idx)
{
    if (selected.size() == m)
    {
        int result{};
        for (int i = 0; i < house.size(); ++i)
        {
            int min = std::numeric_limits<int>::max();
            auto [sx, sy] = house[i];
            for (int j = 0; j < selected.size(); ++j)
            {
                auto [x, y] = chicken[selected[j]];
                min = std::min(min, std::abs(sx - x) + std::abs(sy - y));
            }
            result += min;
        }
        return result;
    }

    std::vector<int> copy(selected);

    int min = std::numeric_limits<int>::max();

    for (int i = idx; i < chicken.size(); ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            copy.push_back(i);
            min = std::min(min, solve(copy, i));
            check[i] = false;
            copy.pop_back();
        }
    }

    return min;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int a;
            std::cin >> a;
            if (a == 1)
            {
                house.emplace_back(j, i);
            }
            else if (a == 2)
            {
                chicken.emplace_back(j, i);
            }
        }
    }

    std::vector<int> selected;
    check.resize(chicken.size(), false);

    std::cout << solve(selected, 0) << '\n';

    return 0;
}