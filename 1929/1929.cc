#include <iostream>
#include <vector>
#include <algorithm>

const std::vector<std::size_t> GetPrimes(std::size_t min, std::size_t max)
{
    if (max <= 1)
    {
        return {};
    }

    std::vector<bool> check(max + 1, true);
    for (std::size_t i = 2; i * i <= max; ++i)
    {
        if (check[i])
        {
            for (std::size_t j = i * i; j <= max; j += i)
            {
                check[j] = false;
            }
        }
    }
    
    std::vector<std::size_t> result;
    for (std::size_t i = 2; i <= max; ++i)
    {
        if (check[i] && i >= min)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;
    std::vector<std::size_t> result = GetPrimes(a, b);
    std::for_each(result.begin(), result.end(), [](std::size_t c){std::cout << c << '\n';});
    return 0;
}