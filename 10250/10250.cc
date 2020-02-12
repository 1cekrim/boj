#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;

    while (t--)
    {
        int h, w, n;
        std::cin >> h >> w >> n;

        int a = n % h;
        int b = n / h + 1;

        if (!(n % h))
        {
            a = h;
            --b;
        }

        std::cout << a * 100 + b << '\n';
    }

    return 0;
}