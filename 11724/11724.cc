#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<bool>> graph(n, std::vector<bool>(n, false));
    std::vector<bool> check(n, false);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        --a;
        --b;

        graph[a][b] = true;
        graph[b][a] = true;
    }

    int result{};
    for (int i = 0; i < n; ++i)
    {
        if (check[i])
        {
            continue;
        }

        std::stack<int> st;
        st.push(i);
        check[i] = true;

        while (!st.empty())
        {
            int now = st.top();
            st.pop();

            for (int j = 0; j < n; ++j)
            {
                if (graph[now][j] == true && !check[j])
                {
                    st.push(j);
                    check[j] = true;
                }
            }
        }

        ++result;
    }

    std::cout << result << '\n';

    return 0;
}