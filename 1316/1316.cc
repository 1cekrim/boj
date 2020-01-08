#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

bool check(std::string_view sv)
{
    std::vector<bool> check(26, false);

    for (int i = 0; i < sv.size(); ++i)
    {
        if (int pos = sv[i] - 'a'; check[pos])
        {
            return false;
        }
        else
        {
            char now = sv[i];
            check[pos] = true;

            while (now == sv[++i])
                ;
            --i;
        }
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int cnt{};
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        if (check(s))
        {
            ++cnt;
        }
    }

    std::cout << cnt << '\n';

    return 0;
}