#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    char c;
    std::cin >> c;
    std::cout << static_cast<int>(c) << '\n';

    return 0;
}