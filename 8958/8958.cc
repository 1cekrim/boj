#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str;

        int cnt{}, score{};
        for (char c : str)
        {
            if (c == 'X')
            {
                cnt = 0;
                continue;
            }
            score += ++cnt;
        }

        std::cout << score << '\n';
    }

    return 0;
}