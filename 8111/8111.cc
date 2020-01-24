#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

void print(std::map<int, int>& trace_num, std::vector<int>& trace, int now)
{
    if (trace[now] == -1)
    {
        std::cout << trace_num[now];
        return;
    }

    print(trace_num, trace, trace[now]);
    std::cout << trace_num[now];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;

    if (t <= 0)
    {
        std::cout << "BRAK\n";
        return 0;
    }

    while (t--)
    {
        int n;
        std::cin >> n;

        std::map<int, int> trace_num;
        std::vector<int> trace(n, 0);
        std::vector<bool> check(n, false);
        std::queue<int> q;
        q.emplace(1);
        trace[1] = -1;
        trace_num[1] = 1;
        check[1] = true;
        bool flag = false;
        while (!q.empty())
        {
            int remainder = q.front();
            q.pop();

            int next[] = { remainder * 10 % n, (remainder * 10 + 1) % n };
            for (int i = 0; i < 2; ++i)
            {
                if (check[next[i]])
                {
                    continue;
                }

                trace_num[next[i]] = i;
                trace[next[i]] = remainder;

                if (!next[i])
                {
                    print(trace_num, trace, next[i]);
                    std::cout << '\n';

                    flag = true;
                    break;
                }
                check[next[i]] = true;
                q.emplace(next[i]);
            }
            if (flag)
            {
                break;
            }
        }
        if (!flag)
        {
            std::cout << "BRAK\n";
        }
    }

    return 0;
}