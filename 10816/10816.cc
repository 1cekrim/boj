#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

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

    int m;
    std::cin >> m;

    while (m--)
    {
        int a;
        std::cin >> a;

        std::cout << std::upper_bound(nums.begin(), nums.end(), a) -
                         std::lower_bound(nums.begin(), nums.end(), a)
                  << ' ';
    }

    return 0;
}