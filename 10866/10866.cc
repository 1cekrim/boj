#include <deque>
#include <iostream>
#include <map>
#include <string>

std::deque<int> dq;

void push_front()
{
    int x;
    std::cin >> x;

    dq.emplace_front(x);
}

void push_back()
{
    int x;
    std::cin >> x;

    dq.emplace_back(x);
}

void front()
{
    if (dq.empty())
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << dq.front() << '\n';
    }
}

void back()
{
    if (dq.empty())
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << dq.back() << '\n';
    }
}

void pop_front()
{
    if (dq.empty())
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << dq.front() << '\n';
        dq.pop_front();
    }
}

void pop_back()
{
    if (dq.empty())
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << dq.back() << '\n';
        dq.pop_back();
    }
}

void size()
{
    std::cout << dq.size() << '\n';
}

void empty()
{
    std::cout << dq.empty() << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    while (n--)
    {
        std::string s;
        std::cin >> s;

        static std::map<std::string, void (*)()> func = {
            { "push_front", push_front },
            { "push_back", push_back },
            { "pop_front", pop_front },
            { "pop_back", pop_back },
            { "size", size },
            { "empty", empty },
            { "front", front },
            { "back", back }
        };

        func[s]();
    }
}