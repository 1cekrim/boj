#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int l, c;
std::vector<char> letter;
std::vector<bool> check;

void solve(int l, int idx, const std::vector<char>& answer)
{
    if (answer.size() == l)
    {
        int mo{}, ja{};
        for (int i = 0; i < answer.size(); ++i)
        {
            if (char ch = answer[i];
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                ++mo;
            }
            else
            {
                ++ja;
            }
        }

        if (mo < 1 || ja < 2)
        {
            return;
        }

        for (char c : answer)
        {
            std::cout << c;
        }
        std::cout << '\n';
    }

    std::vector<char> copy(answer);

    for (int i = idx; i < letter.size(); ++i)
    {
        if (!check[i])
        {
            copy.push_back(letter[i]);
            check[i] = true;
            solve(l, i, copy);
            copy.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> l >> c;
    for (int i = 0; i < c; ++i)
    {
        char tmp;
        std::cin >> tmp;
        letter.push_back(tmp);
    }

    std::vector<char> answer;
    check.resize(c, false);

    std::sort(letter.begin(), letter.end());

    solve(l, 0, answer);

    return 0;
}