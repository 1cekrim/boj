#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int d(int n)
{
    int sum = n;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<bool> check(10001, false);

    for (int i = 1; i <= 10000; ++i)
    {
        if (!check[i])
        {
            int last = i;
            while (last <= 10000)
            {
                last = d(last);
                check[last] = true;
            }
        }

        if (!check[i])
        {
            std::cout << i << '\n';
        }
    }

    return 0;
}