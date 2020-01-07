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

    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        std::cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << '\n';
    }

    return 0;
}