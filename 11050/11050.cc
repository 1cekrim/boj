#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k, result = 1, m = 1;
    std::cin >> n >> k;

    for (int i = 0; i < k; ++i)
    {
        result *= n - i;
        m *= i + 1;
    }

    std::cout << result / m << '\n';

    return 0;
}