#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int nums[2001];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    while (n--)
    {
        int a;
        std::cin >> a;
        nums[a + 1000] = 1;
    }

    for (int i = 0; i <= 2000; ++i)
    {
        if (nums[i])
        {
            std::cout << i - 1000 << ' ';
        }
    }

    std::cout << '\n';

    return 0;
}