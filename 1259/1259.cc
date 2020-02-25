#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true)
    {
        std::string s;
        std::cin >> s;

        if (s == "0")
        {
            break;
        }

        bool flag = false;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                flag = true;
            }
        }

        if (flag)
        {
            std::cout << "no\n";
        }
        else
        {
            std::cout << "yes\n";
        }
    }

    return 0;
}