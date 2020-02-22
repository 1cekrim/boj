#include <algorithm>
#include <iostream>
#include <vector>

void solve(const std::vector<int>& nums, int idx, int m)
{
    static std::vector<bool> check(nums.size());
    static std::vector<int> result(m);
    if (idx == m)
    {
        std::for_each(result.begin(), result.end(),
                      [](int a) { std::cout << a << ' '; });
        std::cout << '\n';
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            result[idx] = nums[i];
            solve(nums, idx + 1, m);
            check[i] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> nums;
    nums.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        nums.emplace_back(a);
    }

    std::sort(nums.begin(), nums.end());

    solve(nums, 0, m);
}