#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<int> times = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

    std::string s;
    std::cin >> s;

    int ans{};
    for (char c : s)
    {
        ans += times[c - 'A'];
    }

    std::cout << ans << '\n';

    return 0;
}