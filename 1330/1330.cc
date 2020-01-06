#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;
    char c;
    if (a < b)
    {
        std::cout << "<\n";
    }
    else if (a > b)
    {
        std::cout << ">\n";
    }
    else
    {
        std::cout << "==\n";
    }
    return 0;
}