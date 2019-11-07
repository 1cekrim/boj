#include <iostream>
#include <string>
#include <string_view>

bool palindrome(const std::string_view& str, std::size_t left,
                std::size_t right)
{
    if (left >= right)
    {
        return true;
    }
    return (str[left] == str[right]) && palindrome(str, left + 1, right - 1);
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << palindrome(s, 0, s.size() - 1);
    return 0;
}