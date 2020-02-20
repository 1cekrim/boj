#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::map<std::string, std::string> book;

    for (int i = 1; i <= n; ++i)
    {
        std::string s;
        std::cin >> s;
        book.emplace(s, std::to_string(i));
        book.emplace(std::to_string(i), s);
    }

    while (m--)
    {
        std::string s;
        std::cin >> s;
        std::cout << book[s] << '\n';
    }

    return 0;
}