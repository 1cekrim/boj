#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using ull = unsigned long long;

class BigInterger
{
 public:
    BigInterger(int n)
    {
        while (n)
        {
            num.push_front(n % 10);
            n /= 10;
        }
    }

    BigInterger(const std::deque<int>& num) : num(num)
    {
        // Do nothing.
    }

    BigInterger operator+(const BigInterger& rhs)
    {
        auto lit = num.rbegin();
        auto rit = rhs.num.rbegin();

        int carry{};
        std::deque<int> result;

        while (lit != num.rend() || rit != rhs.num.rend())
        {
            int value = carry;

            if (lit != num.rend())
            {
                value += *lit;
                ++lit;
            }
            if (rit != rhs.num.rend())
            {
                value += *rit;
                ++rit;
            }

            carry = value / 10;
            result.push_front(value % 10);
        }

        if (carry)
        {
            result.push_front(carry);
        }

        return BigInterger(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInterger& bi)
    {
        for (auto n : bi.num)
        {
            std::cout << n;
        }

        return os;
    }

 private:
    std::deque<int> num;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    if (n <= 1)
    {
        std::cout << n << '\n';
        return 0;
    }

    BigInterger pre = 1, now = 1;
    n -= 1;

    while (--n)
    {
        BigInterger temp = pre;
        pre = now;
        now = temp + now;
    }

    std::cout << now << '\n';

    return 0;
}