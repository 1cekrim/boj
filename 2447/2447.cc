#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int s = n;
            while (true)
            {
                if ((i / s) % 3 == 1 && (j / s) % 3 == 1)
                {
                    std::cout << ' ';
                    break;
                }
                else if (s / 3 == 0)
                {
                    std::cout << '*';
                    break;
                }
                s /= 3;
            }
        }
        std::cout << '\n';
    }
    return 0;
}