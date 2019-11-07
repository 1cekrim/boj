#include <iostream>
#include <vector>

using ll = long long;

ll TotientFunction(ll num)
{
    ll result = num;

    for (ll i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            result /= (i);
            result *= i - 1;

            while (num % i == 0)
            {
                num /= i;
            }
        }
    }

    if (num > 1)
    {
        result /= (num);
        result *= num - 1;
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    ll a;
    std::cin >> a;
    std::cout << TotientFunction(a);
    return 0;
}