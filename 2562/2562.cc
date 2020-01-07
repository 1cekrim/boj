#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int max = std::numeric_limits<int>::min(), idx;

    for (int i = 1; i <= 9; ++i)
    {
        int a;
        std::cin >> a;
        if (max < a)
        {
            idx = i;
            max = a;
        }
    }

    std::cout << max << '\n'
              << idx << '\n';

    return 0;
}