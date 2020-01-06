#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int year;
    std::cin >> year;

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        std::cout << "1\n";
    }
    else
    {
        std::cout << "0\n";
    }
    return 0;
}