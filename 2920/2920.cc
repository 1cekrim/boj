#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    bool asc = true, des = true;

    for (int i = 1; i <= 8; ++i)
    {
        int a;
        std::cin >> a;
        asc = asc && a == i;
        des = des && a == (9 - i);
    }

    std::cout << (asc ? "ascending" : (des ? "descending" : "mixed")) << '\n';

    return 0;
}