#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<int> ans(26, -1);

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        int d = s[i] - 'a';
        if (ans[d] == -1)
        {
            ans[d] = i;
        }
    }

    for (int i : ans)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}