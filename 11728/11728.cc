#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a, b;
    a.reserve(n);
    b.reserve(m);

    for (int i = 0; i < n; ++i)
    {
        int t;
        std::cin >> t;
        a.emplace_back(t);
    }

    for (int j = 0; j < m; ++j)
    {
        int t;
        std::cin >> t;
        b.emplace_back(t);
    }

    for (int i = 0, j = 0; i + j < n + m;)
    {
        if (i < n && a[i] < b[j] || j >= m)
        {
            std::cout << a[i++] << ' ';
        }
        else
        {
            std::cout << b[j++] << ' ';
        }
    }

    std::cout << '\n';

    return 0;
}