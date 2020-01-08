#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;

        std::vector<int> num(a);
        int mean{};
        for (int j = 0; j < a; ++j)
        {
            std::cin >> num[j];
            mean += num[j];
        }
        mean /= a;

        int cnt{};
        for (int j = 0; j < a; ++j)
        {
            if (mean < num[j])
            {
                ++cnt;
            }
        }

        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << static_cast<float>(cnt) / a * 100 << "%\n";
    }

    return 0;
}