#include <cmath>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, sum{};
    std::cin >> n;
    while (n--)
    {
        int a;
        std::cin >> a;

        bool flag = (a == 0 || a == 1);
        for (int i = 2; i <= static_cast<int>(std::sqrt(a)); ++i)
        {
            if (a % i == 0)
            {
                flag = true;
            }
        }

        if (!flag)
        {
            ++sum;
        }
    }

    std::cout << sum;
    return 0;
}