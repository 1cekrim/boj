#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, b, c, cnt{};
    std::cin >> a >> b >> c;

    std::vector<int> num(10, 0);
    int result = a * b * c;
    while (result)
    {
        ++num[result % 10];
        result /= 10;
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << num[i] << '\n';
    }

    return 0;
}