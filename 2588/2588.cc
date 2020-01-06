#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;

    std::cout << (a * (b % 10)) << '\n'
              << (a * ((b / 10) % 10)) << '\n'
              << (a * (b / 100)) << '\n'
              << (a * b) << '\n';

    return 0;
}