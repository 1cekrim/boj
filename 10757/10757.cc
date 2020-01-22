#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string a, b;
    std::cin >> a >> b;

    std::string result;
    int carry{};

    std::string::reverse_iterator ai = a.rbegin(), bi = b.rbegin();
    while (ai != a.rend() || bi != b.rend())
    {
        int now = carry;
        carry = 0;

        if (ai != a.rend())
        {
            now += (*(ai++)) - '0';
        }
        if (bi != b.rend())
        {
            now += (*(bi++)) - '0';
        }

        carry = now / 10;
        now %= 10;

        result.push_back(now + '0');
    }

    if (carry)
    {
        result.push_back(carry + '0');
    }

    std::cout << std::string(result.rbegin(), result.rend()) << '\n';

    return 0;
}