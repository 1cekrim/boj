#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <string_view>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<std::string> data;
        data.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            std::string s;
            std::cin >> s;
            data.emplace_back(s);
        }

        std::sort(data.begin(), data.end(), [](auto& lhs, auto& rhs){
            if (lhs.size() == rhs.size())
            {
                return lhs < rhs;
            }
            return lhs.size() < rhs.size();
        });

        std::set<std::string_view> dict;
        bool flag = true;

        for (int i = 0; i < n && flag; ++i)
        {
            std::string_view sv = data[i];
            while (sv.size())
            {
                if (dict.find(sv) != dict.end())
                {
                    flag = false;
                    break;
                }
                sv.remove_suffix(1);
            }

            dict.emplace(data[i]);
        }

        if (flag)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}