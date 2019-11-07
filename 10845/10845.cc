#include <iostream>
#include <map>
#include <queue>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int n;
    std::cin >> n;
    std::map<std::string, int> commands = { { "push", 0 },  { "pop", 1 },
                                            { "size", 2 },  { "empty", 3 },
                                            { "front", 4 }, { "back", 5 } };
    std::queue<int> q;

    while (n--)
    {
        std::string s;
        std::cin >> s;

        switch (commands.find(s)->second)
        {
            case 0:
            {
                int a;
                std::cin >> a;
                q.push(a);
                break;
            }

            case 1:
            {
                if (q.empty())
                {
                    std::cout << "-1\n";
                }
                else
                {
                    std::cout << q.front() << '\n';
                    q.pop();
                }
                break;
            }

            case 2:
            {
                std::cout << q.size() << '\n';
                break;
            }

            case 3:
            {
                std::cout << q.empty() << '\n';
                break;
            }

            case 4:
            {
                if (q.empty())
                {
                    std::cout << "-1\n";
                }
                else
                {
                    std::cout << q.front() << '\n';
                }
                break;
            }

            case 5:
            {
                if (q.empty())
                {
                    std::cout << "-1\n";
                }
                else
                {
                    std::cout << q.back() << '\n';
                }
                break;
            }
        }
    }
    return 0;
}