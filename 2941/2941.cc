#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string s;
    std::cin >> s;

    std::vector<std::string> cro = { "c=", "c-", "dz=", "d-",
                                     "lj", "nj", "s=",  "z=" };

    for (auto& pattern : cro)
    {
        std::string::size_type pos;
        while ((pos = s.find(pattern)) != std::string::npos)
        {
            s.replace(pos, pattern.size(), "!");
        }
    }

    std::cout << s.size() << '\n';

    return 0;
}