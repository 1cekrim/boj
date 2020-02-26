#include <algorithm>
#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        int k;
        std::cin >> k;

        std::multiset<int> set;

        while (k--)
        {
            char oper;
            int num;

            std::cin >> oper >> num;

            if (oper == 'I')
            {
                set.emplace(num);
            }
            else
            {
                if (!set.empty())
                {
                    if (num == 1)
                    {
                        auto it = set.end();
                        std::advance(it, -1);
                        set.erase(it);
                    }
                    else
                    {
                        set.erase(set.begin());
                    }
                }
            }
        }

        if (set.empty())
        {
            std::cout << "EMPTY\n";
        }
        else
        {
            std::cout << *set.rbegin() << ' ' << *set.begin() << '\n';
        }
    }

    return 0;
}