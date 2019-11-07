#include <iostream>
#include <limits>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::vector<int> data, check;
    std::cin >> n;
    data.reserve(n);
    check.resize(n, 1);

    while (n--)
    {
        int t;
        std::cin >> t;
        data.push_back(t);
    }

    int global_max = 1;
    for (int i = 1; i < data.size(); ++i)
    {
        bool flag = false;
        int max = 0;
        for (int j = 0; j < i; ++j)
        {
            if (data[j] < data[i] && check[j] > max)
            {
                max = check[j];
                flag = true;
            }
        }
        check[i] = max + 1;
        global_max = std::max(global_max, check[i]);
    }
    std::cout << global_max;
    return 0;
}