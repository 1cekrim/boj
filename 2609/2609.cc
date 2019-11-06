#include <iostream>

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b, gcd;
    std::cin >> a >> b;
    gcd = ::gcd(a, b);
    std::cout << gcd << '\n' << (a * b / gcd);
    return 0;
}