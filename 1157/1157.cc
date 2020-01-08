#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string s;
    std::cin >> s;

    std::transform(s.begin(), s.end(), s.begin(), [](char c) { return std::tolower(c); });

    std::vector<int> cnt(26, 0);

    int max = std::numeric_limits<int>::min();
    for (char c : s)
    {
        ++cnt[c - 'a'];
        max = std::max(max, cnt[c - 'a']);
    }

    int pos = -1;
    for (int i = 0; i < cnt.size(); ++i)
    {
        if (max == cnt[i])
        {
            if (pos != -1)
            {
                std::cout << "?\n";
                return 0;
            }
            pos = i;
        }
    }

    std::cout << static_cast<char>('A' + pos) << '\n';

    return 0;
}