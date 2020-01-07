#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, x;
    std::cin >> n >> x;

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        if (a < x)
        {
            std::cout << a << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}