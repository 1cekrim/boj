#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> input;
    input.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        input.emplace_back(a);
    }

    std::vector<int> stack;
    stack.reserve(n + 1);

    std::vector<char> result;
    result.reserve(n);

    auto now = input.begin();
    for (int i = 1; i <= n; ++i)
    {
        stack.emplace_back(i);
        result.emplace_back('+');

        while (!stack.empty())
        {
            if (*now == stack.back())
            {
                stack.pop_back();
                result.emplace_back('-');
                ++now;
            }
            else
            {
                break;
            }
        }
    }

    if (stack.empty())
    {
        std::for_each(result.begin(), result.end(),
                      [](char c) { std::cout << c << '\n'; });
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}