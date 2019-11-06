#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> data;
    data.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        data.push_back(a);
    }

    std::sort(data.begin(), data.end());

    for (int i = 0; i < n; ++i)
    {
        std::cout << data[i] << '\n';
    }

    return 0;
}