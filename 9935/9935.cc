#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    std::string s;
    std::string b;
    std::cin >> s >> b;

    std::stack<char> st;
    std::stack<char> bomb;
    for (char c : b)
    {
        bomb.push(c);
    }

    for (char c : s)
    {
        st.push(c);

        std::stack<char> history;
        while (!bomb.empty() && !st.empty() && st.top() == bomb.top())
        {
            history.push(st.top());
            st.pop();
            bomb.pop();
        }

        bool flag = bomb.empty();
        while (!history.empty())
        {
            if (!flag)
            {
                st.push(history.top());
            }
            bomb.push(history.top());
            history.pop();
        }
    }

    std::string temp;
    while (!st.empty())
    {
        temp.push_back(st.top());
        st.pop();
    }

    if (temp.empty())
    {
        std::cout << "FRULA\n";
    }
    else
    {
        std::cout << std::string(temp.rbegin(), temp.rend()) << '\n';
    }

    return 0;
}