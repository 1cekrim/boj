#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

struct comp
{
    bool operator()(const std::string& a, const std::string& b)
    {
        if (a.size() == b.size())
        {
            return a > b;
        }
        return a.size() > b.size();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::set<std::string> check;
    std::priority_queue<std::string, std::vector<std::string>, comp> q;

    while (n--)
    {
        std::string s;
        std::cin >> s;
        if (check.find(s) == check.end())
        {
            check.emplace(s);
            q.emplace(s);
        }
    }

    while (!q.empty())
    {
        std::cout << q.top() << '\n';
        q.pop();
    }

    return 0;
}