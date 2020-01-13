#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int r1, s;
    std::cin >> r1 >> s;

    std::cout << (s * 2 - r1) << '\n';
    return 0;
}