#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    while (true)
    {
        int a, b;
        std::cin >> a;
        if (std::cin.eof())
        {
            break;
        }
        std::cin >> b;
        std::cout << a + b << '\n';
    }

    return 0;
}