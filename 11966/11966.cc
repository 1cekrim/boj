#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    
    std::cout << (n == (n & -n) ? 1 : 0) << '\n';

    return 0;
}