#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> hear;
    while (n--)
    {
        std::string s;
        std::cin >> s;
        hear.emplace_back(s);
    }

    std::sort(hear.begin(), hear.end());

    std::vector<std::string> see;
    while (m--)
    {
        std::string s;
        std::cin >> s;
        see.emplace_back(s);
    }

    std::sort(see.begin(), see.end());

    std::vector<std::string> result;
    for (auto& s : see)
    {
        if (*std::lower_bound(hear.begin(), hear.end(), s) == s)
        {
            result.emplace_back(s);
        }
    }

    std::cout << result.size() << '\n';
    for (auto& s : result)
    {
        std::cout << s << '\n';
    }

    return 0;
}