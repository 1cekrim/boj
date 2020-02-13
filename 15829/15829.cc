#include <iostream>

using ll = long long;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int l;
    std::cin >> l;

    std::string s;
    std::cin >> s;

    constexpr ll r = 31;
    constexpr ll m = 1234567891;
    ll h{};

    for (int i = 0; i < s.size(); ++i)
    {
        ll res = s[i] - 'a' + 1;
        ll now = r;
        int t = i;

        while (t)
        {
            if (t & 1)
            {
                res *= now;
                res %= m;
            }
            t >>= 1;
            now *= now;
            now %= m;
        }

        h += res;
        h %= m;
    }

    std::cout << h << '\n';

    return 0;
}