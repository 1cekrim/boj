#include <iostream>
#include <vector>

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

    int n;
    std::cin >> n;

    int data[100];

    while (n--)
    {
        int nn;
        std::cin >> nn;

        for (int i = 0; i < nn; ++i)
        {
            std::cin >> data[i];
        }

        std::size_t sum{};
        for (int i = 0; i < nn - 1; ++i)
        {
            for (int j = i + 1; j < nn; ++j)
            {
                sum += gcd(data[i], data[j]);
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}