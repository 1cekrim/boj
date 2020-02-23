#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true)
    {
        std::string s;
        std::getline(std::cin, s);

        if (s == ".")
        {
            break;
        }

        std::vector<char> stack;
        stack.reserve(s.size());

        auto check = [&stack](char c) {
            if (c == '(' || c == '[')
            {
                stack.emplace_back(c);
            }
            else if (c == ')')
            {
                if (!stack.empty() && stack.back() == '(')
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (c == ']')
            {
                if (!stack.empty() && stack.back() == '[')
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
            return true;
        };

        auto it = s.begin();
        for (; it != s.end(); ++it)
        {
            if (!check(*it))
            {
                std::cout << "no\n";
                break;
            }
        }

        if (it != s.end())
        {
            continue;
        }

        if (stack.empty())
        {
            std::cout << "yes\n";
        }
        else
        {
            std::cout << "no\n";
        }
    }
}