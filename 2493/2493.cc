#include <iostream>
#include <stack>
#include <tuple>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::stack<std::tuple<int, int>> st;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        std::cin >> a;

        int ans{};
        while (!st.empty())
        {
            auto [pos, height] = st.top();
            if (height > a)
            {
                ans = pos;
                break;
            }

            st.pop();
        }

        std::cout << ans << ' ';
        st.emplace(i, a);
    }

    std::cout << '\n';

    return 0;
}