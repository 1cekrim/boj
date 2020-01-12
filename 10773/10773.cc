#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::stack<int> st;
    st.push(0);
    for (int i = 0; i < n; ++i)
    {
        int top = st.top();
        int a;
        std::cin >> a;
        if (a == 0)
        {
            st.pop();
        }
        else
        {
            st.push(a + top);
        }
    }

    std::cout << st.top() << '\n';

    return 0;
}