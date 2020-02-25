#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> nums;
    nums.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        nums.emplace_back(a);
    }

    std::sort(nums.begin(), nums.end());

    int result{};
    for (int i = 0; i < n; ++i)
    {
        result += nums[i] * (n - i);
    }

    std::cout << result << '\n';

    return 0;
}