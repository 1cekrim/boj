#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix1(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> matrix1[i][j];
        }
    }

    int k;
    std::cin >> m >> k;

    std::vector<std::vector<int>> matrix2(m, std::vector<int>(k));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            std::cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int ans{};
            for (int q = 0; q < m; ++q)
            {
                ans += matrix1[i][q] * matrix2[q][j];
            }
            std::cout << ans << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}