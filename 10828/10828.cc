#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::stack<int> st;

    static std::map<std::string, std::function<void()>> func = {
        { "push",
          [&st]() {
              int a;
              std::cin >> a;
              st.push(a);
          } },
        { "top",
          [&st]() { std::cout << (st.empty() ? -1 : st.top()) << '\n'; } },
        { "size", [&st]() { std::cout << st.size() << '\n'; } },
        { "empty", [&st]() { std::cout << (st.empty() ? 1 : 0) << '\n'; } },
        { "pop",
          [&st]() {
              func["top"]();
              if (!st.empty())
              {
                  st.pop();
              }
          } }
    };

    while (n--)
    {
        std::string s;
        std::cin >> s;
        func[s]();
    }

    return 0;
}