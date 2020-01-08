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
        int r;
        std::string s;
        std::cin >> r >> s;

        for (char c : s)
        {
            for (int j = 0; j < r; ++j)
            {
                std::cout << c;
            }
        }
        std::cout << '\n';
    }

    return 0;
}