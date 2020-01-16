#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int f, s, g, u, d;
    std::cin >> f >> s >> g >> u >> d;

    std::vector<bool> check(f + 1, false);
    std::queue<std::tuple<int, int>> q;

    q.emplace(s, 0);
    while (!q.empty())
    {
        auto [pos, time] = q.front();
        q.pop();

        if (pos == g)
        {
            std::cout << time << '\n';
            return 0;
        }

        int npos[] = { pos + u, pos - d };
        for (int i = 0; i < 2; ++i)
        {
            if (npos[i] > 0 && npos[i] <= f && !check[npos[i]])
            {
                q.emplace(npos[i], time + 1);
                check[npos[i]] = true;
            }
        }
    }

    std::cout << "use the stairs\n";

    return 0;
}